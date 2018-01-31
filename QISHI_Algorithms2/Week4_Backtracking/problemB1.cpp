class Solution {
public:
    /*
     * @param nums: A list of integers.
     * @return: A list of permutations.
     */
     
    void dfs(vector<int> &nums, int n, int sbeg, vector<vector<int>>& res){
        if(sbeg >= n - 1){
            res.push_back(vector<int>(nums));
            return;
        }
        
        for(int i = sbeg; i < n; ++i){
            swap(nums, sbeg, i);
            dfs(nums, n, sbeg + 1, res);
            swap(nums, sbeg, i);
        }
    }
    
    void swap(vector<int>& nums, int i, int j){
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
    
    vector<vector<int>> permute(vector<int> &nums) {
        // write your code here
        vector<vector<int>> res;
        dfs(nums, nums.size(), 0, res);
        return res;
    }
};
