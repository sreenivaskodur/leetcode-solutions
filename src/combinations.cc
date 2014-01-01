class Solution {
private:
    vector<vector<int> > result;
    int n,k;
    
    void combine_helper(int curr,vector<int> partial_combination){
        
        if(partial_combination.size() == k){
            result.push_back(partial_combination);
        } else if(curr <= n){
            combine_helper(curr + 1,partial_combination);
            partial_combination.push_back(curr);
            combine_helper(curr + 1,partial_combination);
        }
    }
    
public:
    vector<vector<int> > combine(int n, int k) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        
        result.clear();
        this->k = k;
        this->n = n;
        
        vector<int> t;
        combine_helper(1,t);
        return result;
    }
};
