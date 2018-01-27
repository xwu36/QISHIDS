class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        vector<int> path;
        dfs(nums, 0, path, result);
        return result;
    }
    
    void dfs(vector<int>& nums, int sp, vector<int>& path, vector<vector<int>>& result){
        result.push_back(vector<int>(path));
        for(int i = sp; i < nums.size(); i++){
            if(i != sp && nums[i] == nums[i - 1]) continue;
            path.push_back(nums[i]);
            dfs(nums, i + 1, path, result);
            path.pop_back();
        }
    }
};
