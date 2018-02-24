class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        //release[i][j] = max(release[i][j - 1], hold + prices[j])
        //hold = max(hold, release[i - 1][j] - prices[j])
        int n = prices.size();
        if(k == 0 || n <= 1) return 0;
        
        if(k >= n / 2){
            int hold = -prices[0];
            int release = 0;
            for(int i = 1; i < n; i++){
                release = max(release, hold + prices[i]);
                hold = max(release - prices[i], hold);
            }
            return release;
        }
        
        vector<vector<int>> release(k + 1, vector<int>(n, 0));
        for(int i = 1; i <= k; i++){
            int hold = release[i - 1][0] - prices[0];
            for(int j = 1; j < n; j++){
                release[i][j] = max(release[i][j - 1], hold + prices[j]);
                hold = max(hold, release[i - 1][j] - prices[j]);
            }
        }
        return release[k][n - 1];
    }
};
