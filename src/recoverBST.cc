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
    void recoverTree_helper(TreeNode *root, TreeNode *&n1, TreeNode *&n2, TreeNode *&prev){
        if(root == NULL) return;
        
        recoverTree_helper(root->left,n1,n2,prev);
        
        if(prev != NULL and prev->val > root->val){
            n2 = root;
            if(n1 == NULL) n1 = prev;
        }
        
        prev = root;
        recoverTree_helper(root->right,n1,n2,prev);
    }
    
public:
    void recoverTree(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        
        TreeNode *n1 = NULL, *n2 = NULL, *prev = NULL;
        recoverTree_helper(root,n1,n2,prev);
        
        if(n1 != NULL and n2 != NULL){
            int temp = n1->val;
            n1->val = n2->val;
            n2->val = temp;
        }
    }
};
