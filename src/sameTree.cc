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
    bool isSameTree(TreeNode *p, TreeNode *q) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        
        if(p == NULL and q == NULL) return true;
        
        else if(p != NULL and q != NULL and p->val == q->val and
                isSameTree(p->left,q->left) and isSameTree(p->right,q->right)) return true;
                
        return false;
    }
};
