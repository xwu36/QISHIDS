class Solution {
    //------increase------ || ------decrease------ || ------increase------ || ------decrease------ 
    //Thus, if condition is (nums[m] < nums[m + 1])
    public int findPeakElement(int[] nums) {
        int n = nums.length;
        int l = 0;
        int r = n - 1;
        while(l < r){
            int m = (r - l) / 2 + l;
            if(nums[m] < nums[m + 1]) l = m + 1;
            else r = m;
        }
        return l;
    }
}
