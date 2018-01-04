public class MedianFinder {
    
    PriorityQueue<Integer> minHeap;
    PriorityQueue<Integer> maxHeap;
    int cur;
    /** initialize your data structure here. */
    public MedianFinder() {
        minHeap = new PriorityQueue<Integer>();
        maxHeap = new PriorityQueue<Integer>(new MyComparator());
    }
    
    public void addNum(int num) {
        if(maxHeap.size() == 0){
            maxHeap.add(num);
            return;
        }
        
        if(maxHeap.size() > minHeap.size()){
            if(num >= maxHeap.peek()) minHeap.add(num);
            else{
                cur = maxHeap.poll();
                maxHeap.add(num);
                minHeap.add(cur);
            }
        }
        else{
            if(num <= minHeap.peek()) maxHeap.add(num);
            else{
                cur = minHeap.poll();
                minHeap.add(num);
                maxHeap.add(cur);
            }
        }
    }
    
    public double findMedian() {
        return minHeap.size() == maxHeap.size() ? (minHeap.peek() + maxHeap.peek())/2.0 : maxHeap.peek();
    }
    
    class MyComparator implements Comparator<Integer>{
        public int compare(Integer num1, Integer num2){
            return num2 - num1;
        }
    }
}

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */
