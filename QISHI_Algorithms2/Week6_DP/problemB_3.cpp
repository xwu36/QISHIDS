class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
        dp[0][0] = true;
        for(int j = 1; j < m; j++)
            dp[0][j + 1] = p[j] == '*' && dp[0][j - 1];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(p[j] != '*')
                    dp[i + 1][j + 1] = dp[i][j] && (s[i] == p[j] || p[j] == '.');
                else
                    dp[i + 1][j + 1] = dp[i + 1][j - 1] 
                    || ((s[i] == p[j - 1] || p[j - 1] == '.') && dp[i][j + 1]); 
            }
        }
        return dp[n][m];
    }
};
