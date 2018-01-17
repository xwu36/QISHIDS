class Solution {
    private int[][] ds = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    private int count = 0;
    public int numIslands(char[][] grid) {
        if(grid.length == 0 || grid[0].length == 0)
            return 0;
        int n = grid.length;
        int m = grid[0].length;
        int[] parents = new int[n * m];
        for(int i = 0; i < n * m; i++)
            parents[i] = i;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == '1'){
                    count++;
                    for(int[] d : ds){
                        int cur_i = i + d[0];
                        int cur_j = j + d[1];
                        if(cur_i < 0 || cur_i >= n || cur_j < 0 || cur_j >= m || grid[cur_i][cur_j] == '0')
                            continue;
                        union(parents, cur_i * m + cur_j, i * m + j);
                    }
                }
            }
        }
        return count;
    }
    
    public int find(int[] parents, int x){
        if(parents[x] == x)
            return x;
        return find(parents, parents[x]);
    }
    
    public void union(int[] parents, int x, int y){
        int x_p = find(parents, x);
        int y_p = find(parents, y);
        if(x_p != y_p){
            parents[x_p] = y_p;
            count--;
        }
    }
}
