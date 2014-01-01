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
    int result;
    
    void sumNumbers(TreeNode* root, int curr){
        if(root->left == NULL and root->right == NULL){
            result += curr * 10 + root->val;
        } else{
            curr = curr * 10 + root->val;
            
            if(root->left != NULL)
                sumNumbers(root->left,curr);
                
            if(root->right != NULL)
                sumNumbers(root->right,curr);
        }
    }
    
public:
    int sumNumbers(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        
        result = 0;
        
        if(root != NULL)
            sumNumbers(root,0);
            
        return result;
    }
};
