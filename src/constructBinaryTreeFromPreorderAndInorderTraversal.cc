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
    vector<int> preorder;
    vector<int> inorder;
    
    TreeNode *buildTree_helper(int start, int end, int &curr){
        
        if(start <= end and curr < inorder.size()){
            
            int index = start;
            while(index <= end){
                if(inorder[index] == preorder[curr]){
                    curr++;
                    break;
                }
                index ++;
            }
            
            TreeNode *curr_node = new TreeNode(inorder[index]);
            
            curr_node->left = buildTree_helper(start,index - 1,curr);
            curr_node->right = buildTree_helper(index + 1,end,curr);
            
            return curr_node;
        }
        
        return NULL;
    }
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        
        this->inorder.clear(); this->preorder.clear();
        
        if(inorder.size() == 0) return NULL;
        
        this->inorder = inorder;
        this->preorder = preorder;
        
        int curr = 0;
        return buildTree_helper(0,inorder.size() - 1,curr);
    }
};
