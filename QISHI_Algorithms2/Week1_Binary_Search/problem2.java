class Solution {
    public int findRadius(int[] houses, int[] heaters) {
        Arrays.sort(heaters);
        int n = heaters.length;
        int res = 0;
        for(int house : houses){
            int index = equal_greater(house, heaters);
            int left = index == 0 ? Integer.MAX_VALUE : house - heaters[index - 1];
            int right = index == n ? Integer.MAX_VALUE : heaters[index] - house;
            res = Math.max(res, Math.min(left, right));
        }
        return res;
    }
    
    // ----heaters[m] < house----|---heaters[m] >= house---
    // ---------Left/T-----------|-------Right/F-----------
    // return the first element on the right side
    public int equal_greater(int house, int[] heaters){
        int l = 0;
        int r = heaters.length;
        while(l < r){
            int m = (r - l) / 2 + l;
            if(heaters[m] < house) l = m + 1;
            else r = m;
        }
        return l;
    }
}
