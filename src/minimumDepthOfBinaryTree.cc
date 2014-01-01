/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int minDepth(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        
        if(root == NULL) return 0;
        else if(root->left == NULL and root->right == NULL) return 1;
        
        int lh = INT_MAX,rh = INT_MAX;
        
        if(root->left != NULL)
            lh = minDepth(root->left);
        
        if(root->right != NULL)
            rh = minDepth(root->right);
        
        return (lh > rh) ? rh + 1 : lh + 1;
    }
};
