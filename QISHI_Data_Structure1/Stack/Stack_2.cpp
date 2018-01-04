class Solution {
public:
    int singleNumber(vector<int>& nums) {
        //XOR, if the same number, x^x == 1, otherwise 0;
        for (int i = 1; i < nums.size(); ++i)
            nums[0] ^= nums[i];
        return nums[0];
    }
};
