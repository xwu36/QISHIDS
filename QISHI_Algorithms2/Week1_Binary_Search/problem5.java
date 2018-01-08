class Solution {
public:
    // this problem is pretty much the same as 378. Kth Smallest Element in a Sorted Matrix, which was covered in the sweek1 doc
    // input: [1, 3, 1], k = 2
	// output should be 2
	// Binary algorithm:
	//              ---------Left/T---------|---------Right/F---------	
	// pair distance:          0            |2             2
    // ***
    // for kth number T we know, if a number M < T, then M has less than k numbers which are less than or equal to M
    // if a number M >= T, then M has at least k numbers which are greater than or equal to M.
    // ***
    // we know the output must be in the range of [0, 2]
    // and we have
	// pair distance                      :                    0                1|               2             
	// number less than or equal to itself:                    1                1|               3                        
	//                                     ---count_number_less_equal_self < k---|---count_number_less_equal_self >= k---
	//                                     -----------------Left/T---------------|-----------------Right/F---------------
	// so we need to return the first element on the right side
    // below is an example to caculate the number of pair distance we have less than M
    // [1, 1, 3] cur_distance = 2
    // for the first 1, we have 2 numbers(1, 3), 1 + 2 == 3, 1 <= 3, 3 <= 3, thus 3 - 0 - 1 = 2, 
    // for the second 1, we have 1 number(3) 1 + 2 == 3, 3 <= 3, thus 3 - 1 - 1 = 1
    // for 3, we have 0 number 3 - 2 - 1 = 0
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int l = 0;
        int r = nums[n - 1] - nums[0] + 1;
        while(l < r){
            int m = (r - l) / 2 + l;
            if(less_equal_count(nums, m, n) < k) l = m + 1;
            else r = m;
        }
        return l;
    }
    
    int less_equal_count(vector<int>& nums, int m, int n){
        int count = 0;
        for(int i = 0; i < n; i++){
            count += less_equal_count_BS(nums, m + nums[i], n) - i;
        }
        return count;
    }
    
    // same as upper_bound - 1
    int less_equal_count_BS(vector<int>& nums, int m, int n){
        int l = 0;
        int r = n;
        while(l < r){
            int mid = (r - l) / 2 + l;
            if(nums[mid] <= m) l = mid + 1;
            else r = mid;
        }
        return l - 1;
    }
};
