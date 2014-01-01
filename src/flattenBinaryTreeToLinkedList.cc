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
    TreeNode *prev;
    
    void flatten_helper(TreeNode *root){
        if(root != NULL){
            TreeNode *l = root->left;
            TreeNode *r = root->right;
            
            if(prev != NULL){
                prev->left = NULL;
                prev->right =  root;
            }
            
            prev = root;
            
            flatten_helper(l);
            flatten_helper(r);
        }
    }
public:
    void flatten(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        
        prev = NULL;
        flatten_helper(root);
    }
};
