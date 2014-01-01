/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
struct Node{
    int val;
    Node *prev;
};

class Solution {
private:
    vector<TreeNode*> generateTree_helper(int start, int end){
        
        vector<TreeNode*> result;
        
        if(start > end){
            result.push_back(NULL);
        } else{
            
            for(int i = start; i <= end; i++){
                vector<TreeNode*> left_trees = generateTree_helper(start,i - 1);
                vector<TreeNode*> right_trees = generateTree_helper(i + 1,end);
                
                for(int l = 0; l < left_trees.size(); l++){
                    for(int r = 0; r < right_trees.size(); r++){
                        TreeNode *root = new TreeNode(i);
                        root->left = left_trees[l];
                        root->right = right_trees[r];
                        result.push_back(root);
                    }
                }
            }
        }
        
        return result;
    }
    
public:
    vector<TreeNode *> generateTrees(int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        
        return generateTree_helper(1,n);
    }
};
