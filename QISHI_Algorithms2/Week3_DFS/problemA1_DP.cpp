class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        vector<vector<int>> dp = vector<vector<int>>(nums.size() + 1, vector<int>(2001));
        if(S > 2001 || S < -2001) return 0;
        for (auto &i : dp)
            fill(i.begin(), i.end(), 0);
        dp[0][1000] = 1;
        for(int i = 0; i < nums.size(); i++){
            for(int j = 0; j < 2001; j++){
                if(j >= nums[i])
                    dp[i + 1][j] = dp[i][j - nums[i]];
                if(j + nums[i] < 2001)
                    dp[i + 1][j] += dp[i][j + nums[i]];
            }
        }
        return dp[nums.size()][S + 1000] == -1? 0 : dp[nums.size()][S + 1000];
    }
    
    //dp[i + 1][j] = dp[i][j - nums[i]]
    //dp[i + 1][j] += dp[i][j + nums[i]]
    
    // [1, 1, 1] 
    //   0 1 2 3 4 5 6
    // 0 # # # 0 # # #
    // 1 # # 1 # 1 # #
    // 2 # 1 0 2 0 1 #
    
};
