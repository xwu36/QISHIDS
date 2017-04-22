class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        if(nums.empty()) return result;
        
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < nums.size(); i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int left = i + 1, right = nums.size() - 1;
            while(left < right){
                if(nums[left] + nums[right] + nums[i] == 0){
                    vector<int>temp = { nums[i], nums[left], nums[right]};
                    result.push_back(temp);
                    while(nums[left] == nums[left + 1]) left++;
                    left++;
                    while(nums[right] == nums[right - 1]) right--;
                    right--;
                }else if(nums[left] + nums[right] + nums[i] < 0){
                    left++;
                }else right--;
            }
        }
        return result;
    }
};
