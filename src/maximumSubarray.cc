class Solution {
public:
    int maxSubArray(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        
        int curr_sum = 0, max_sum = INT_MIN;
        
        for(int i = 0; i < n; i++){
            
            curr_sum += A[i];
            
            if(max_sum < curr_sum) max_sum = curr_sum;
            
            if(curr_sum < 0) curr_sum = 0;
        }
        
        return max_sum;
    }
};
