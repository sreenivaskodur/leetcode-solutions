/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
private:
    deque<TreeLinkNode*> curr_level;
    deque<TreeLinkNode*> next_level;
    
    void connect_helper(TreeLinkNode *root){
        if(root == NULL) return;
        
        curr_level.push_back(root);
        
        while(curr_level.size() > 0){
            
            while(curr_level.size() > 0){
                TreeLinkNode *n = curr_level.front();
                
                if(n->left != NULL)
                    next_level.push_back(n->left);
                    
                if(n->right != NULL)
                    next_level.push_back(n->right);
                    
                curr_level.pop_front();
                
                if(curr_level.size() > 0){
                    n->next = curr_level.front();
                } else{
                    n->next = NULL;
                }
            }
            
            curr_level = next_level;
            next_level.clear();
        }
    }
public:
    void connect(TreeLinkNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        
        curr_level.clear();
        next_level.clear();
        
        connect_helper(root);
    }
};
