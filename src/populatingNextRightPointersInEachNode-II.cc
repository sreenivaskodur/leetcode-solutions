/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        
        if(root == NULL) return;
        
        deque<TreeLinkNode*> curr_level;
        deque<TreeLinkNode*> next_level;
        
        curr_level.push_back(root);
        
        while(curr_level.size() > 0){
            
            while(curr_level.size() > 1){
                TreeLinkNode* t = curr_level.front();
                
                if(t->left != NULL)
                    next_level.push_back(t->left);
                if(t->right != NULL)
                    next_level.push_back(t->right);
                    
                curr_level.pop_front();
                t->next = curr_level.front();
            }
            
            curr_level.front()->next = NULL;
            
            if(curr_level.front()->left != NULL)
                next_level.push_back(curr_level.front()->left);
            if(curr_level.front()->right != NULL)
                next_level.push_back(curr_level.front()->right);
                
            curr_level.pop_front();
            
            curr_level = next_level;
            next_level.clear();
        }
    }
};
