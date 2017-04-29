/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == nullptr) return false;
        ListNode* slow = head;
        ListNode* fast = head;
        int step = 0;
        while(fast != nullptr){
            if(fast->next == nullptr || fast->next->next == nullptr) return false;
            if(fast == slow && step++ != 0) return true;
            slow = slow->next;
            fast = fast->next->next;
        }
        return false;
    }
};
