class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> nums(n);
        for(int i = 0; i < n; i++)
            nums[i] = i+ 1;
        while(k != 1){
            nextPermutation(nums, n);
            k--;
        }
        string s;
        for(int num : nums)
            s.push_back('0' + num);
        return s;
    }
    
    void nextPermutation(vector<int>& nums, int n){
        int i = n - 2;
        while(i >= 0 && nums[i] >= nums[i + 1])
            i--;
        if(i >= 0){
            int j = n - 1;
            while(j >= 0 && nums[i] >= nums[j])
                j--;
            swap(nums, i, j);
        }
        reverse(nums, i + 1);
    }
    
    void swap(vector<int>& nums, int i, int j){
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
    
    void reverse(vector<int>& nums, int sp){
        int end = nums.size() - 1;
        while(sp < end){
            swap(nums, sp++, end--);
        }
    }
};
