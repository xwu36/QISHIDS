class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int l = 0;
        int r = nums.size() - 1;
        while(l <= r){
            int m = quick_select(nums, l, r);
            if(m == k - 1) return nums[m];
            if(m < k - 1) l = m + 1;
            else r = m - 1;
        }
        return -1;
    }
    
    int quick_select(vector<int>& nums, int l, int r){
        int pivot = nums[r];
        int j = l;
        for(int i = l; i < r; i++){
            if(nums[i] >= pivot){
                swap(nums[i], nums[j]);
                j++;
            }
        }
        swap(nums[j], nums[r]);
        return j;
    }
};
