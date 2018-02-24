class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        //dp[i] indicates s[0]---s[i] can be segmented into a space-separated sequence
        int n = s.size();
        set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        for(int i = 1; i <= n; i++){
            for(int j = i - 1; j >= 0; j--){
                int l = i - j;
                if(dp[j] && wordSet.find(s.substr(j, l)) != wordSet.end()){
                    // cout << s.substr(j, l) << endl;
                    dp[i] = true;
                }
            }
        }
        // for(auto num : dp)
        //     cout << num << " " << endl;
        return dp[n];
    }
};
