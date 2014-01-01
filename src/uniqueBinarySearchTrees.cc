class Solution {
public:
    int numTrees(int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        
        static map<int,int> lookup;
        
        if(lookup.find(n) != lookup.end()) return lookup[n];
        
        else if(n == 0){
            lookup[0] = 1;
            return 1;
        } else if(n <= 2){
            lookup[n] = n;
            return n;
        }
        
        int num_bst = 0;
        for(int i = 0; i < n; i++){
            num_bst = num_bst + numTrees(i) * numTrees(n - i - 1);
        }
        
        lookup[n] = num_bst;
        return num_bst;
    }
};
