public class Solution {
    public List<Integer> topKFrequent(int[] nums, int k) {
        List<Integer>[] buckets = new List[nums.length + 1];
        Map<Integer, Integer> frequentMap = new HashMap<Integer, Integer>();
        
        for(int i = 0; i < nums.length; i++) frequentMap.put(nums[i], frequentMap.getOrDefault(nums[i], 0) + 1);
        
        for(int key : frequentMap.keySet()){
            int value = frequentMap.get(key);
            if(buckets[value] == null) buckets[value] = new ArrayList<>();
            buckets[value].add(key);
        }
        
        List<Integer> res = new ArrayList<Integer>();
        
        for(int i = buckets.length - 1; i >= 0 && res.size() < k; i--){
            if(buckets[i] != null) res.addAll(buckets[i]);
        }
        
        return res;
    }
}
