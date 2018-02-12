class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0 || matrix[0].size() == 0)
            return false;
        int n = matrix.size();
        int m = matrix[0].size();
        if(matrix[0][0] > target || matrix[n - 1][m - 1] < target) return false;
        for(int i = 0; i < n; i++){
            if(matrix[i][0] > target && matrix[i][m - 1] < target) continue;
            if(target < matrix[i][0]) return false;
            if(binarySearch(matrix[i], target))
                return true;
        }
        return false;
    }
    
    bool binarySearch(const vector<int>& arr, int target){
        int l = 0;
        int r = arr.size();
        while(l < r){
            int m = (r - l) / 2 + l;
            if(arr[m] == target) return true;
            if(arr[m] < target) l = m + 1;
            else r = m;
        }
        return false;
    }
};

