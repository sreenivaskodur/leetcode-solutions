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
    vector<vector<int> > levelOrder(TreeNode *root) {
        
        vector<vector<int> > result;
        
        if(root == NULL) return result;
        
        deque<TreeNode*> curr_level, next_level;
        
        curr_level.push_back(root);
        
        while(curr_level.size() > 0){
            
            vector<int> level;
            
            while(curr_level.size() > 0){
                TreeNode* t = curr_level.front();
                
                if(t->left != NULL){
                    next_level.push_back(t->left);
                }
                
                if(t->right != NULL){
                    next_level.push_back(t->right);
                }
                
                curr_level.pop_front();
                level.push_back(t->val);    
            }
            
            result.push_back(level);
            curr_level = next_level;
            next_level.clear();
        }
        
        return result;
    }
};
