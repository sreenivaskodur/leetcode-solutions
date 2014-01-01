class Solution {
public:
    int uniquePaths(int m, int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        
        vector<vector<int> > matrix(m, vector<int>(n,1));
        
        for(int row = 1; row < m; row++){
            for(int col = 0; col < n; col++){
                if(col == 0){
                    matrix[row][0] = matrix[row - 1][0];
                }
                
                else{
                    matrix[row][col] = matrix[row - 1][col] + matrix[row][col - 1];
                }
            }
        }
        
        return matrix[m - 1][n - 1];
    }
};
