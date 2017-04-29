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
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        ListNode* root = new ListNode(0);
        root->next = head;
        ListNode* cur = root->next;
        ListNode* nex = root->next->next;
        while(nex != nullptr){
            cur->next = nex->next;
            nex->next = root->next;
            root->next = nex;
            nex = cur->next;
        }
        return root->next;
    }
};
