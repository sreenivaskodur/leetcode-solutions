class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        
        int m = matrix.size(), n = matrix[0].size();
        int left = 1, right = m * n;
        
        while(left < right){
            
            int mid = left + (right - left) / 2;
            int row_mid = (mid % n == 0) ? mid / n - 1 : mid / n, col_mid = (mid % n == 0) ? n - 1 : (mid % n) - 1;
            
            if(matrix[row_mid][col_mid] == target) return true;
            
            else if(matrix[row_mid][col_mid] > target){
                right = row_mid * n + col_mid;
            }
            
            else{
                left = row_mid * n + col_mid + 2;
            }
        }
        
        if(left == right){
            int row = (left % n == 0) ? left / n - 1 : left / n, col = (left % n == 0) ? n - 1 : (left % n) - 1;
            return target == matrix[row][col];
        }
        
        return false;
    }
};
