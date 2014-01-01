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
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        
        if(head == NULL or head->next == NULL) return false;
        
        ListNode *one_x = head, *two_x = head->next->next;
        
        while(two_x != NULL and two_x != one_x){
            one_x = one_x->next;
            
            if(two_x->next == NULL) return false;
            
            two_x = two_x->next->next;
        }
        
        return !(two_x == NULL);
    }
};
