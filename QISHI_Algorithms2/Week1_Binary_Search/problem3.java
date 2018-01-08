class Solution {
    public int[] searchRange(int[] nums, int target) {
        if(nums == null || nums.length == 0) return new int[]{-1, -1};
        return new int[]{findLeft(nums, target), findRight(nums, target)};
    }
    
    public int findLeft(int[] nums, int target){
        int l = 0;
        int r = nums.length;
        while(l < r){
            int m = (r - l) / 2 + l;
            if(nums[m] < target) l = m + 1;
            else r = m;
        }
        return l == nums.length || nums[l] != target ? -1 : l;
    }
    
    public int findRight(int[] nums, int target){
        int l = 0;
        int r = nums.length;
        while(l < r){
            int m = (r - l) / 2 + l;
            if(nums[m] <= target) l = m + 1;
            else r = m;
        }
        return l - 1 == -1 || nums[l - 1] != target ? -1 : l - 1;
    }
}
