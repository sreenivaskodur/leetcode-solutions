class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        
        vector<vector<int> > matrix(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(),0));
        
        matrix[0][0] = 1 - obstacleGrid[0][0];
        
        for(int col = 1; col < obstacleGrid[0].size(); col++){
            matrix[0][col] = (1 - obstacleGrid[0][col]) * matrix[0][col - 1];
        }
        
        for(int row = 1; row < obstacleGrid.size(); row++){
            for(int col = 0; col < obstacleGrid[0].size(); col++){
                if(obstacleGrid[row][col] == 1){
                    matrix[row][col] = 0;
                }
                
                else if(col == 0){
                    matrix[row][0] = matrix[row - 1][0];
                }
                
                else{
                    matrix[row][col] = matrix[row - 1][col] + matrix[row][col - 1];
                }
            }
        }
        
        return matrix[obstacleGrid.size() - 1][obstacleGrid[0].size() - 1];
    }
};
