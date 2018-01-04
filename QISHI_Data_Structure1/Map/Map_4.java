public class Solution {
    public int subarraySum(int[] nums, int k) {
        Map<Integer, Integer> cum = new HashMap<Integer, Integer>();
        int sum = 0, count = 0;
        cum.put(0, 1);
        for(int i = 0; i < nums.length; i++){
            sum += nums[i];
            if(cum.containsKey(sum - k)) count += cum.get(sum - k);
            cum.put(sum, cum.getOrDefault(sum, 0) + 1);
        } 
        return count;
    }
}
