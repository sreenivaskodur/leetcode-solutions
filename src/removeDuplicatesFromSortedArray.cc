class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        
        if(n == 0) return 0;
        
        int prev = A[0], count = 1;
        
        for(int i = 1; i < n; i++){
            if(prev != A[i]){
                count ++;
                prev = A[i];
                A[count - 1] = A[i]; 
            }
        }
        
        return count;
    }
};
