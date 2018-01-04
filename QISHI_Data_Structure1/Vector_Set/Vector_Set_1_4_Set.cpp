class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        set<vector<int>> result;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, 0, 0, target, result, temp);
        return vector<vector<int>>(result.begin(), result.end());
    }
    
    void dfs(vector<int>& candidates, int spt, int sum, int target, set<vector<int>>& result, vector<int>& temp){
        
        if(sum == target) {
            result.insert(temp);
            return;
        }
        
        for(int i = spt; i < candidates.size(); i++){
            if(sum + candidates[i] > target) return;
            temp.push_back(candidates[i]);
            dfs(candidates, i+1, sum + candidates[i], target, result, temp);
            temp.pop_back();
        }
        return;
    }
};
