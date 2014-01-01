class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        
        int curr = 0, actual = -1;
        
        while(curr < n){
            if(A[curr] != elem){
                A[actual + 1] = A[curr];
                actual ++;
            }
            
            curr ++;
        }
        
        return actual + 1;
    }
};
