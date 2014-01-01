class Solution {
public:
    int jump(int A[], int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        
        int num_steps = 0;
        int curr_bound = 0;
        int max_bound = 0;
        
        for(int i = 0; i < n; i++){
            
            if(i > curr_bound){
                curr_bound = max_bound;
                num_steps ++;
            }
            
            max_bound = (max_bound > A[i] + i) ? max_bound : A[i] + i;
        }
        
        return num_steps;
    }
};
