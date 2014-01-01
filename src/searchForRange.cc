class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        
        int start = 0, end = n - 1;
        
        int f = firstOccurence(A,0,n-1,target);
        int l = lastOccurence(A,0,n-1,target);
        
        vector<int> result;
        result.push_back(f);
        result.push_back(l);
        return result;
    }
    
    int firstOccurence(int A[], int start, int end, int target){
        
        if(start > end) return -1;
        
        int mid = start + (end - start) / 2;
        
        if(target == A[mid]){
            int f = firstOccurence(A,start,mid - 1,target);
            if(f != -1) return f;
            return mid;
        }
        
        else if(target < A[mid]) return firstOccurence(A,start,mid - 1,target);
        return firstOccurence(A,mid + 1,end,target);
    }
    
    int lastOccurence(int A[], int start, int end, int target){
        
        if(start > end) return -1;
        
        int mid = start + (end - start) / 2;
        
        if(target == A[mid]){
            int l = lastOccurence(A,mid + 1,end,target);
            if(l != -1) return l;
            return mid;
        }
        
        else if(target < A[mid]) return lastOccurence(A,start,mid - 1,target);
        return lastOccurence(A,mid + 1,end,target);
    }
};
