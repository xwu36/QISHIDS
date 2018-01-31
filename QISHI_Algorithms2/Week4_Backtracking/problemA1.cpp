class Solution {
public:
    int ds[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
        int col = board[0].size();
        int n = word.size();
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(dfs(board, row, col, word, n, i, j, 0))
                    return true;
            }
        }
        return false;
    }
    
    bool dfs(vector<vector<char>>& board, int row, int col, string& word, int n, int i, int j, int sp){
        if(board[i][j] != word[sp]) return false;
        if(sp == n - 1) return true;
        
        char tmp = board[i][j];
        board[i][j] = '#';
        for(auto d : ds){
            int cur_i = i + d[0];
            int cur_j = j + d[1];
            if(cur_i < 0 || cur_j < 0 || cur_i >= row || cur_j >= col) continue;
            if(dfs(board, row, col, word, n, cur_i, cur_j, sp + 1)) return true;
        }
        board[i][j] = tmp;
        
        return false;
    }
};
