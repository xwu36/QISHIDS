class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0 || matrix[0].size() == 0)
            return false;
        int n = matrix.size();
        int m = matrix[0].size();
        return searchMatrix(matrix, 0, m - 1, 0, n - 1, target);
    }
    
    bool searchMatrix(const vector<vector<int>>& matrix, int left, int right, int up, int down, int target) {
        // cout << "left: " << left << " right: " << right << " up: " << up << " down: " << down << endl;
        if(left <= right && up <= down){
            int center_x = (left + right) / 2;
            int center_y = (up + down) / 2;
            if(matrix[center_y][center_x] == target) return true;
            if(matrix[center_y][center_x] < target){
                return searchMatrix(matrix, center_x + 1, right, up, center_y, target) 
                    || searchMatrix(matrix, left, right, center_y + 1, down, target);
            }else{
                return searchMatrix(matrix, left, right, up, center_y - 1, target) 
                    || searchMatrix(matrix, left, center_x - 1, center_y, down, target);
            }
        }
        return false;
    }
};

