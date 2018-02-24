class Solution {
public:
    int numSquares(int n) {
        vector<int> perfect_squares;
        for(int i = 1; i * i <= n; i++)
            perfect_squares.push_back(i * i);
        //dp[i] indicates the least number of perfect square numbers
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for(int i = 1; i <= n; i++)
            for(const auto num : perfect_squares)
                if(i >= num)
                    dp[i] = min(dp[i], dp[i - num] + 1);
        return dp[n];
    }
};
