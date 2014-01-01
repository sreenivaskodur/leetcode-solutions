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
public:
    bool isValidBST(TreeNode *root,int min = INT_MIN, int max = INT_MAX) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        
        if(root == NULL) return true;
        
        else if(root->val > min and root->val < max and
                isValidBST(root->left,min,root->val) and isValidBST(root->right,root->val,max)){
            return true;            
        }
        
        return false;
    }
};
