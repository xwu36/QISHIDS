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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* root = new ListNode(0);
        ListNode* ptr = root;
        while(l1 != nullptr && l2 != nullptr){
            if(l1->val < l2->val){
                root->next = l1; 
                l1 = l1->next;
            }else{
                root->next = l2; 
                l2 = l2->next;
            }
            root = root->next;
        }
        root->next = l1? l1 : l2;
        return ptr->next;
    }
};
