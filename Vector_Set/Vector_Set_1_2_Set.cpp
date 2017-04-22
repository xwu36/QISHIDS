/*
 * this solution is a very easy one for us to avoid the duplicates, but it is not a good one
 * because we have to convert the set to vector eventually, which needs extra operations and time. 
 * Acutally we can just use vector to solve this problem by adding some conditions to remove the duplicates
 */
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        set<vector<int>> result;
        if(nums.empty()) return vector<vector<int>>(result.begin(), result.end());  //if nums is empty, return empty result
        
        sort(nums.begin(), nums.end());         //first sort the nums vector
        
        /*
         * we need three pointers, one is the traverse pointer for going throngh nums
         * for each traverse pointer, we have left and right pointer, which would move towards the middle position.
         * if their sum is 0, we put them into set, if sum is less than 0, we move the left pointer one position right
         * else we move the right pointer one position left
         */
        for(int i = 0; i < nums.size(); i++){ 
            int left = i + 1;
            int right = nums.size()-1;
            while(left < right){
                if(nums[i] + nums[left] + nums[right] == 0){
                    vector<int> v = {nums[i], nums[left], nums[right]};
                    result.insert(v);
                    left++;
                    right--;
                }else if(nums[i] + nums[left] + nums[right] < 0) left++;
                else if(nums[i] + nums[left] + nums[right] > 0) right--;
            }
        }
        
        return vector<vector<int>>(result.begin(), result.end());
    }
};
