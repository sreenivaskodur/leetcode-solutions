class Solution {
public:
    bool canJump(int A[], int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        
        if(n <= 1) return true;
        
        int max_bound = 0;
        
        for(int i = 0; i < n; i++){
            if(max_bound < i) return false;
            max_bound = (max_bound > A[i] + i) ? max_bound : A[i] + i;
            if(max_bound >= n - 1) return true;
        }
        
        return max_bound >= n - 1;
    }
};
