class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        
        vector<int> spiral;
        
        if(matrix.size() == 0) return spiral;
        
        int row_start = 0, row_end = matrix.size() - 1;
        int col_start = 0, col_end = matrix[0].size() - 1;
        
        while(row_start < row_end and col_start < col_end){
            
            for(int i = col_start; i <= col_end; i++){
                spiral.push_back(matrix[row_start][i]);
            }
            
            for(int i = row_start + 1; i <= row_end; i++){
                spiral.push_back(matrix[i][col_end]);
            }
            
            for(int i = col_end - 1; i >= col_start; i--){
                spiral.push_back(matrix[row_end][i]);
            }
            
            for(int i = row_end - 1; i > row_start; i--){
                spiral.push_back(matrix[i][col_start]);
            }
            
            row_start ++; row_end --;
            col_start ++; col_end --;
        }
        
        if(row_start < row_end and col_start == col_end){
            for(int i = row_start; i <= row_end; i++){
                spiral.push_back(matrix[i][col_start]);
            }
        } else if(col_start < col_end and row_start == row_end){
            for(int i = col_start; i <= col_end; i++){
                spiral.push_back(matrix[row_start][i]);
            }
        } else if(col_start == col_end and row_start == row_end){
            spiral.push_back(matrix[row_start][col_start]);
        }
        
        return spiral;
    }
};
