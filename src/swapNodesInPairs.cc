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
    ListNode *swapPairs(ListNode *head) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        
        if(head == NULL) return head;
        
        ListNode *curr = head;
        
        while(curr != NULL){
            if(curr->next != NULL){
                int temp = curr->val;
                curr->val = curr->next->val;
                curr->next->val = temp;
                
                curr = curr->next;
            }
            
            curr = curr->next;
        }
        
        return head;
    }
};
