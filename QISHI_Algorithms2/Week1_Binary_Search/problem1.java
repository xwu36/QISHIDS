class Solution {
    // ---letters[m] <= target---|---letters[m] > target---
    // ---------Left/T-----------|-------Right/F-----------
    // return the first element on the right side
    public char nextGreatestLetter(char[] letters, char target) {
        if(letters == null || letters.length == 0) return 'a';
        int n = letters.length;
        int l = 0;
        int r = n;
        while(l < r){
            int m = (r - l) / 2 + l;
            if(letters[m] <= target) l = m + 1;
            else r = m;
        }
        return l == n ? letters[0] : letters[l];
    }
}
