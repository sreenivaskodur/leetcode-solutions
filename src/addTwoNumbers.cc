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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        int carry = 0;
        ListNode *temp1 = l1, *temp2 = l2;
        
        while(temp1->next != NULL and temp2->next != NULL){
            int res = temp1->val + temp2->val + carry;
            temp1->val = res % 10;
            carry = res / 10;
            
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        
        int res = temp1->val + temp2->val + carry;
        temp1->val = res % 10;
        carry = res / 10;
        
        if(temp1->next == NULL){
            temp1->next = temp2->next;
        }
        
        while(temp1->next != NULL){
            int res = temp1->next->val + carry;
            temp1->next->val = res % 10;
            
            temp1 = temp1->next;
            carry = res / 10;
        }
        
        if(temp1->next == NULL and carry > 0){
            temp1->next = new ListNode(carry % 10);
            carry = carry / 10;
            temp1->next->next = NULL;
            temp1 = temp1->next;
        }
        
        while(carry > 0){
            temp1->next = new ListNode(carry % 10);
            temp1->next->next = NULL;
            temp1 = temp1->next;
            carry = carry / 10;
        }
        
        return l1;
    }
};
