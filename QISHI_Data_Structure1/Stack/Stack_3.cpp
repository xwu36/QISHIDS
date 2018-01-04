class Solution {
public:
    bool isPowerOfTwo(int n) {
        //AND, if x is power of 2, x could be represented as 100...00, then x - 1 would be 99..99, x&(x-1) = 0
        return n > 0 && !(n&(n-1));
    }
};
