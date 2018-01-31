class Solution {
public:
    /*
     * @param A: A list of integers
     * @return: A boolean
     */
    bool canJump(vector<int> &A) {
        // write your code here
        int n = A.size();
        int steps = 0;
        for(int i = 0; i < n - 1; ++i){
            steps = max(A[i], steps) - 1;
            if(steps < 0) return false;
        }
        return true;
    }
};
