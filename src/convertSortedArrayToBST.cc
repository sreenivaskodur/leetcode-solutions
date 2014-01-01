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
    vector<int> nums;
    
    TreeNode *sortedArrayToBST(int start, int end){
        if(start > end) return NULL;
        
        int mid = start + (end - start) / 2;
        
        TreeNode* curr = new TreeNode(nums[mid]);
        curr->left = sortedArrayToBST(start, mid - 1);
        curr->right = sortedArrayToBST(mid + 1, end);
        return curr;
    }
    
public:
    TreeNode *sortedArrayToBST(vector<int> &num) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        
        nums.clear();
        this->nums = num;
        
        return sortedArrayToBST(0,num.size() - 1);
    }
};
