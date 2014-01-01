class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        
        int curr_a = m - 1, curr_b = n - 1, final_a = m + n - 1;
        
        while(curr_a >= 0 and curr_b >= 0){
            if(A[curr_a] > B[curr_b]){
                A[final_a] = A[curr_a --];
            } else{
                A[final_a] = B[curr_b --];
            }
            
            final_a --;
        }
        
        while(curr_a >= 0){
            A[final_a --] = A[curr_a --]; 
        }
        
        while(curr_b >= 0){
            A[final_a --] = B[curr_b --];
        }
    }
};
