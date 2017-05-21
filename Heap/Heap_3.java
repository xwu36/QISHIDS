/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        PriorityQueue<ListNode> heap = new PriorityQueue<ListNode>(new myComparator());
        ListNode start = new ListNode(0);
        ListNode origin = start;
        
        for(int i = 0; i < lists.length; i++) {
            if(lists[i] != null)
                heap.add(lists[i]);
        }
        
        while(heap.size() > 0){
            ListNode cur = heap.poll();
            start.next = cur;
            start = start.next;
            if(cur.next != null)
                heap.add(cur.next);
        }
        
        return origin.next;
    }
    
    class myComparator implements Comparator<ListNode>{
        public int compare(ListNode listNode1, ListNode listNode2) {
            return listNode1.val - listNode2.val;
        }
    }
}
