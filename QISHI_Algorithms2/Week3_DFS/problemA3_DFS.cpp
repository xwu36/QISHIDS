class Solution {
public:
    const double eps = 0.001;
    bool judgePoint24(vector<int>& nums) {
        vector<double> nums_(4);
        for(int i = 0; i < 4; i++) nums_[i] = nums[i];  
        return dfs(nums_, 4);
    }
    
    bool dfs(vector<double> nums, int n){
  
        if(n == 1){
            if(abs(nums[0] - 24) < eps) return true;
            else return false;
        }
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i == j) continue;
                int u = 0;
                vector<double> curNums(n - 1);
                for(int k = 0; k < n; k++)
                    if(k != i && k != j)
                        curNums[u++] = nums[k];

                curNums[u] = nums[i] + nums[j];
                if(dfs(curNums, n - 1)) return true;
                
                curNums[u] = nums[i] - nums[j];
                if(dfs(curNums, n - 1)) return true;
                
                curNums[u] = nums[i] * nums[j];
                if(dfs(curNums, n - 1)) return true;
                
                if(nums[j] != 0){
                    curNums[u] = nums[i] / nums[j];
                    if(dfs(curNums, n - 1)) return true;
                }
            }
        }
        return false;
    }
};
