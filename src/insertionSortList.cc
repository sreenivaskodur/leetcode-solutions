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
    ListNode *insertionSortList(ListNode *head) {
        
        if(head == NULL or head->next == NULL) return head;
        
        ListNode *curr = head->next, *prev = head;
        head->next = NULL;
        
        while(curr != NULL){
            
            ListNode *temp = prev, *tprev = NULL;
            
            while(temp != NULL){
                if(curr->val > temp->val){
                    tprev = temp;
                    temp = temp->next;
                } else{
                    break;
                }
            }
            
            ListNode *t = curr->next;
            
            curr->next = temp;
            
            if(tprev != NULL) tprev->next = curr;
            else prev = curr;
            
            curr = t;
        }
        
        return prev;
    }
};
