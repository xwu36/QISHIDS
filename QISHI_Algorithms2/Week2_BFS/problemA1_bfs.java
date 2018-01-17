class Solution {
    private int[][] ds = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    public int numIslands(char[][] grid) {
        if(grid.length == 0 || grid[0].length == 0)
            return 0;
        int n = grid.length;
        int m = grid[0].length;
        int count = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == '1'){
                    count++;
                    bfs(grid, i, j, n, m);
                }
            }
        }
        return count;
    }
    
    public void bfs(char[][] grid, int i, int j, int n, int m){
        Queue<Integer> queue = new LinkedList<>();
        queue.add(i * m + j);
        while(queue.size() > 0){
            int cur = queue.poll();
            int i_ = cur / m;
            int j_ = cur % m;
            for(int[] d : ds){
                int cur_i = i_ + d[0];
                int cur_j = j_ + d[1];
                if(cur_i >= n || cur_i < 0 || cur_j >= m || cur_j < 0 || grid[cur_i][cur_j] == '0')
                    continue;
                grid[cur_i][cur_j] = '0';
                queue.add(cur_i * m + cur_j);
            }
        }
    }
}
