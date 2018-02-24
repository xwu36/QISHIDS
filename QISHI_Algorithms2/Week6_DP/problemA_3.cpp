class Solution {
public:
    vector<int> countBits(int num) {
        //dp[i] indicates the number of ones 
        //dp[i] = dp[i >> 2] + i & 1;
        vector<int> dp(num + 1, 0);
        for(int i = 1; i <= num; i++)
            dp[i] = dp[i >> 1] + (i & 1);
        return dp;
    }
};
