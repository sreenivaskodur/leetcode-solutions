/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

struct Interval_BST_Node{
    int start;
    int end;
    
    vector<Interval*> lst;
    
    Interval_BST_Node *left;
    Interval_BST_Node *right;
};

class Solution {
private:
    void insert_into_BST(Interval_BST_Node *root, Interval *interval){
        
        Interval_BST_Node *prev = NULL;
        
        while(root != NULL){
            if(root->start >= interval->start and root->end >= interval->end ||
               root->start >= interval->start and root->end <= interval->end ||
               root->start <= interval->start and root->end >= interval->end ||
               root->start <= interval->start and root->end <= interval->end){
                   
                root->start = (root->start > interval->start) ? interval->start : root->start;
                root->end = (root->end > interval->end) ? root->end : interval->end;
                
                root->lst.push_back(interval);
                return;
            } else if(root->end < interval->start){
                prev = root; root = root->right;
            } else if(root->start > interval->end){
                prev = root; root = root->left;
            }
        }
        
        if(prev->start > interval->end){
            prev->left = new Interval_BST_Node;
            
            prev->left->start = interval->start;
            prev->left->end = interval->end;
            prev->lst.push_back(interval);
            prev->left->left = prev->left->right = NULL;
        } else{
            prev->right = new Interval_BST_Node;
            
            prev->right->start = interval->start;
            prev->right->end = interval->end;
            prev->lst.push_back(interval);
            prev->right->left = prev->right->right = NULL;
        }
    }
    
    vector<Interval> inorder_traversal;
    
    void inorder_BST(Interval_BST_Node *root){
        
        if(root->left == NULL) return;
        
        inorder_BST(root->left);
        
        Interval curr(root->start,root->end);
        inorder_traversal.push_back(curr);
        
        inorder_BST(root->right);
    }
    
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        
        if(intervals.size() == 0) return inorder_traversal;
        
        Interval_BST_Node *root = new Interval_BST_Node;
        root->start = intervals[0].start;
        root->end = intervals[0].end;
        root->lst.push_back(&intervals[0]);
        root->left = root->right = NULL;
        
        for(int i = 1; i < intervals.size(); i++){
            this->insert_into_BST(root,&intervals[i]);
        }
        
        inorder_BST(root);
        return inorder_traversal;
    }
};
