class Solution {
public:
    vector<unordered_map<int, int>> memo;
    int findTargetSumWays(vector<int>& nums, int S) {
        memo = vector<unordered_map<int, int>>(nums.size());
        return dfs(nums, nums.size(), 0, S);
    }
    
    int dfs(vector<int>& nums, int n, int sp, int S){
        
        if(sp == n){
            if(S == 0) return 1;
            else return 0;
        }
        
        if(memo[sp].count(S))
            return memo[sp][S];
        
        memo[sp][S] = dfs(nums, n, sp + 1, S + nums[sp]) + dfs(nums, n, sp + 1, S - + nums[sp]);
        return memo[sp][S];
    }    
};
