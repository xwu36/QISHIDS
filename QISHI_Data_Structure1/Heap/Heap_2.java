public class Solution {
    public int findKthLargest(int[] nums, int k) {
        PriorityQueue<Integer> heap = new PriorityQueue<Integer>(new Comparator<Integer>() {
            public int compare(Integer x, Integer y) {
                return y - x;
            }
        });
        
        for(int i = 0; i < nums.length; i++){
            heap.add(nums[i]);
        }
        
        while(--k != 0){
            heap.poll();
        }
        
        return heap.poll();
    }
}
