/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    TreeNode *listToBST_helper(ListNode* &head,int start, int end){
        
        if(start <= end){
            int mid = start + (end - start) / 2;
            
            TreeNode *l = listToBST_helper(head,start,mid - 1);
            
            TreeNode *curr = new TreeNode(head->val);
            
            head = head->next;
            TreeNode *r = listToBST_helper(head,mid + 1,end);
                
            curr->left = l; curr->right = r;
            return curr;
        }
        
        return NULL;
    }
    
public:
    TreeNode *sortedListToBST(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        
        int length = 0;
        ListNode *temp = head;
        
        while(temp != NULL){
            temp = temp->next;
            length ++;
        }
        
        if(length == 0) return NULL;
        else if(length == 1) return new TreeNode(head->val);
        
        return listToBST_helper(head,1,length);
    }
};
