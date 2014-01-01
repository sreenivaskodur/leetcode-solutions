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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        
        ListNode *modified = new ListNode(-40);
        modified->next = head;
        ListNode *forward_ptr = modified;
        
        for(int i = 0; i < n; i++){
            forward_ptr = forward_ptr->next;
        }
        
        ListNode *curr_ptr = modified, *prev = NULL;
        
        while(forward_ptr != NULL){
            prev = curr_ptr;
            curr_ptr = curr_ptr->next;
            forward_ptr = forward_ptr->next;
        }
        
        prev->next = curr_ptr->next;
        curr_ptr->next = NULL;
        
        delete curr_ptr;
        return modified->next;
    }
};
