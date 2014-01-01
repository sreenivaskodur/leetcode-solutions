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
    int maxSum;
    
    int maxPathSumHelper(TreeNode *root){
        int l = (root->left == NULL) ? INT_MIN : maxPathSumHelper(root->left);
        int r = (root->right == NULL) ? INT_MIN : maxPathSumHelper(root->right);
        
        int result = root->val + ((l > r) ? l : r);
        
        if(l < 0 and r < 0){
            result = root->val;
        }
        
        maxSum = (maxSum > result) ? maxSum : result;
        
        if(l > 0 and r > 0 and l + r + root->val > maxSum){
            maxSum = l + r + root->val;
        }
        
        return result;
    }
    
public:
    int maxPathSum(TreeNode *root) {
        if(root == NULL) return 0;
        
        this->maxSum = INT_MIN;
        maxPathSumHelper(root);
        return maxSum;
    }
};
