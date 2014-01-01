class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        
        vector<int> array(n,-1);
        
        for(int i = 0 ; i < n; i++){
            
            if(1<= A[i] and A[i] <= n){
                
                array[A[i] - 1] = 1;
            }
        }
        
        for(int i = 0; i < n; i++){
            
            if(array[i] == -1) return i + 1;
        }
        
        return n + 1;
    }
};
