/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    ListNode* merge(ListNode *lst_one, ListNode *lst_two){
        ListNode *head, *prev;
        
        if(lst_one->val > lst_two->val){
            head = lst_two;
            lst_two = lst_two->next;
        } else{
            head = lst_one;
            lst_one = lst_one->next;
        }
        
        prev = head;
        
        while(lst_one != NULL and lst_two != NULL){
            if(lst_one->val > lst_two->val){
                prev->next = lst_two;
                lst_two = lst_two->next;
            } else{
                prev->next = lst_one;
                lst_one = lst_one->next;
            }
            
            prev = prev->next;
        }
        
        prev->next = (lst_one == NULL) ? lst_two : lst_one;
        return head;
    }
    
    ListNode* sortList(ListNode *head, int length){
        
        if(length == 1) return head;
        
        ListNode *lst_one = head, *prev = NULL;
        
        int half_length = length / 2;
        
        while(half_length > 0){
            prev = head;
            head = head->next;
            half_length --;
        }
        
        prev->next = NULL;
        return merge(sortList(lst_one,length / 2), sortList(head,length - length / 2));
    }
    
public:
    ListNode *sortList(ListNode *head) {
        if(head == NULL) return head;
        
        int length = 0;
        
        ListNode *temp = head;
        while(temp != NULL){
            temp = temp->next;
            length ++;
        }
        
        return sortList(head,length);
    }
};