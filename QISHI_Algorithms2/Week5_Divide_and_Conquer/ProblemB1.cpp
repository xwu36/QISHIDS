class Solution {
public:
    /*
     * @param A: an array
     * @return: total of reverse pairs
     */
    long long reversePairs(vector<int> &A) {
        // write your code here
        return inversion_merge(A, 0, A.size() - 1);
    }
    
    long long inversion_merge(vector<int> &nums, int l, int r){
		long long count = 0;
		if(l < r){
			int m = (r - l) / 2 + l;
			count = inversion_merge(nums, l, m);
			count += inversion_merge(nums, m + 1, r);
			count += inversion_mergeSort(nums, l, m + 1, r);
		}
		return count;
	}
	
	long long inversion_mergeSort(vector<int> &nums, int l, int m, int r){
		long long count = 0;
        vector<int> left(nums.begin() + l, nums.begin() + m);
        vector<int> right(nums.begin() + m, nums.begin() + r + 1);
		int l1 = 0, l2 = 0, k = l;
		while(l1 < m - l || l2 < r - m + 1){
			if(l2 >= r - m + 1 || (l1 < m - l && left[l1] <= right[l2])){
				nums[k++] = left[l1];
				l1++;
			}else{
				count += m - l - l1;
				nums[k++] = right[l2];
				l2++;
			}
		}
		return count;
	}
};
