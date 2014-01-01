class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        
        int start = 0, end = n - 1;
        
        while(start < end){
            
            int mid = start + (end - start) / 2;
            
            if(A[mid] == target) return mid;
            
            else if(target > A[mid]) start = mid + 1;
            
            else end = mid - 1;
        }
        
        if(start < n and A[start] < target) return start + 1;
        else return start;
    }
};
