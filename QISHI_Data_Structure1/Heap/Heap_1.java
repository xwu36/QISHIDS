public class Solution {
    public List<Integer> topKFrequent(int[] nums, int k) {
        PriorityQueue<Map.Entry<Integer, Integer>> heap = new PriorityQueue<Map.Entry<Integer, Integer>>(new myComparator());
        Map<Integer, Integer> map = new HashMap<Integer, Integer>();
        List<Integer> list = new ArrayList<Integer>();
        
        //cacluate frequence for every unique number
        for(int i = 0; i < nums.length; i++){
            if(!map.containsKey(nums[i])) map.put(nums[i], 0);
            map.put(nums[i], map.get(nums[i]) + 1);
        }
        
        //transfer the map set into heap
        for(Map.Entry<Integer, Integer> entry : map.entrySet()){
            heap.add(entry);
        }
        
        //pop the first k elements of heap out and push them into list
        while(k-- > 0){
            list.add(heap.poll().getKey());
        }
        
        return list;
    }
    
    class myComparator implements Comparator<Map.Entry<Integer, Integer>>{
        public int compare(Map.Entry<Integer, Integer> entry1, Map.Entry<Integer, Integer> entry2) {
            return entry2.getValue() - entry1.getValue();
        }
    }
}
