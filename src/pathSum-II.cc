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
    TreeNode *n;
    Node *parent;
    
    Node(TreeNode *n,Node *parent):n(n),parent(parent){}
};

class Solution {
private:
    vector<vector<int> > all_paths;
    
    void pathSum_helper(TreeNode *root, Node *parent, int curr_sum, int sum){
        
        if(root->left == NULL and root->right == NULL){ 
            
            if(sum == curr_sum + root->val){
                vector<int> path;
            
                Node *temp = new Node(root,parent);
            
                do{
                    path.push_back(temp->n->val);
                    temp = temp->parent;
                }while(temp != NULL);
                
                reverse(path.begin(),path.end());
                all_paths.push_back(path);
            }
            
            return;
        }
        
        Node *c = new Node(root,parent);
        
        if(root->left != NULL)
        pathSum_helper(root->left,c,curr_sum + root->val,sum);
        
        if(root->right != NULL)
        pathSum_helper(root->right,c,curr_sum + root->val,sum);
    }
public:
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        
        all_paths.clear();

        if(root == NULL) return all_paths;
        
        pathSum_helper(root,NULL,0,sum);
        return all_paths;
    }
};
