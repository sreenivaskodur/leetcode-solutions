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
    ListNode *detectCycle(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        
        if(head == NULL or head->next == head) return head;
        else if(head->next == NULL) return NULL;
        
        ListNode *one_x = head, *two_x = head->next->next;
        
        while(one_x != NULL and two_x != NULL and one_x != two_x){
            one_x = one_x->next;
            if(two_x->next == NULL) return NULL;
            two_x = two_x->next->next;
       }
       
       if(one_x == NULL or two_x == NULL) return NULL;
       
       int cycle_length = 1;
       ListNode *temp = one_x->next;
       
       while(temp != one_x){
           temp = temp->next;
           cycle_length ++;
       }
       
       temp = one_x = head;
       
       while(cycle_length > 0){
           temp = temp->next;
           cycle_length --;
       }
       
       while(temp != one_x){
           temp = temp->next;
           one_x = one_x->next;
       }
       
       return temp;
    }
};
