class Solution {
public:
    int search(int A[], int n, int target) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        
        int start = 0, end = n - 1;
        
        while(start < end){
            
            int mid = start + (end - start) / 2;
            
            if(A[mid] == target) return mid;
            
            else if(start == mid){ start = mid + 1;}
            
            else if( (A[start] <= target and target <= A[mid - 1]) ||
                     (A[mid + 1] <= A[end] and !(A[mid + 1] <= target and target <= A[end]))){
                    end = mid - 1;
            }
            
            else{ start = mid + 1; }
        }
        
        if(start == end and start < n and A[start] == target) return start;
        
        return -1;
    }
};
