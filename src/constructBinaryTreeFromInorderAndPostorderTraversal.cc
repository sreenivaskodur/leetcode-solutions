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
    vector<int> inorder;
    vector<int> rev_postorder;
    
    TreeNode *buildTree(int start_inorder,int end_inorder, int &curr_rev_postorder){
        
        if(start_inorder <= end_inorder and curr_rev_postorder < rev_postorder.size()){
            
            int index = start_inorder;
            
            while(index <= end_inorder){
                if(inorder[index] == rev_postorder[curr_rev_postorder]){
                    curr_rev_postorder ++;
                    break;
                }
                
                index ++;
            }
            
            assert(index <= end_inorder);
            
            TreeNode *curr_node = new TreeNode(inorder[index]);
            
            curr_node->right = buildTree(index + 1,end_inorder,curr_rev_postorder);
            curr_node->left = buildTree(start_inorder,index - 1,curr_rev_postorder);
            return curr_node;
        }
        
        return NULL;
    }
    
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        
        if(inorder.size() == 0) return NULL;
        
        this->inorder.clear(); this->rev_postorder.clear();
        this->inorder = inorder;
        
        rev_postorder = postorder;
        reverse(rev_postorder.begin(),rev_postorder.end());
        
        int curr = 0;
        return buildTree(0,inorder.size() - 1,curr);
    }
};
