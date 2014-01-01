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
    bool isBalanced_helper(TreeNode *root, int &height){
        
        if(root == NULL){
            height = 0;
            return true;
        }
        
        int lh, rh;
        
        if(isBalanced_helper(root->left,lh) and isBalanced_helper(root->right,rh)){
            height = (lh > rh) ? lh + 1: rh + 1;
            if(abs(lh - rh) <= 1) return true;
        }
        
        return false;
    }
    
public:
    bool isBalanced(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        
        int h = 0;
        return isBalanced_helper(root,h);
    }
};
