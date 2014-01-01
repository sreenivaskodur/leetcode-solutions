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
    bool isSymmetric_helper(TreeNode* l, TreeNode *r){
        
        if(l == NULL and r == NULL) return true;
        
        else if(l != NULL and r != NULL and l->val == r->val and
                isSymmetric_helper(l->left,r->right) and isSymmetric_helper(l->right,r->left)){
            return true;            
        }
        
        return false;
    }
    
public:
    bool isSymmetric(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        
        if(root == NULL) return true;
        return isSymmetric_helper(root->left,root->right);
    }
};
