public class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> cum = new HashMap<Integer, Integer>();
        for(int i = 0; i < nums.length; i++){
            if(cum.containsKey(target - nums[i]) && i != cum.get(target - nums[i]))
                return new int[]{i, cum.get(target - nums[i])};
            else
                cum.put(nums[i], i);
        }
        return null;
    }
}
