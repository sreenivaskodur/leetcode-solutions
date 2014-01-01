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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        
        ListNode *head = NULL, *prev = NULL;
        if(l1 == NULL) return l2;
        else if(l2 == NULL) return l1;
        else if(l1->val > l2->val){
            head = l2;
            l2 = l2->next;
            prev = head;
        }
        else{
            head = l1;
            l1 = l1->next;
            prev = head;
        }
        
        while(l1 != NULL and l2!= NULL){
            if(l1->val > l2->val){
                prev->next = l2;
                l2 = l2->next;
                prev = prev->next;
            }
            
            else{
                prev->next = l1;
                l1 = l1->next;
                prev = prev->next;
            }
        }
        
        if(l1 != NULL) prev->next = l1;
        else prev->next = l2;
        
        return head;
    }
};
