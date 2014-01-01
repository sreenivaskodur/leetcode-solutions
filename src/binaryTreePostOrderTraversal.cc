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
    vector<int> postorderTraversal(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        
        vector<int> postorder;
        
        if(root == NULL) return postorder;
        
        stack<TreeNode*> s;
        
        s.push(root);
        
        TreeNode *prev = NULL;
        
        while(!s.empty()){
            
            TreeNode *curr = s.top();
            
            if(prev == NULL or prev->left == curr or prev->right == curr){
                if(curr->left != NULL)
                    s.push(curr->left);
                else if(curr->right != NULL)
                    s.push(curr->right);
            } else if(prev == curr->left){
                if(curr->right != NULL)
                    s.push(curr->right);
            } else{
                postorder.push_back(curr->val);
                s.pop();
            }
            
            prev = curr;
        }
    }
};
