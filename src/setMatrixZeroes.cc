class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        
        int nrows = matrix.size();
    
        if(nrows == 0) return;
        
        int ncols = matrix[0].size();
        
        bool zero_first_row = false, zero_first_col = false;
        
        for(int i = 0; i < nrows; i++){
            for(int j = 0; j < ncols; j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = matrix[0][j] = 0;
                    
                    if(j == 0){
                        zero_first_col = true;
                    } if(i == 0){
                        zero_first_row = true;
                    }
                }
            }
        }
        
        for(int i = 1; i < ncols; i++){
            if(matrix[0][i] == 0){
                for(int j = 0; j < nrows; j++){
                    matrix[j][i] = 0;
                }
            }
        }
        
        for(int i = 1; i < nrows; i++){
            if(matrix[i][0] == 0){
                for(int j = 0; j < ncols; j++){
                    matrix[i][j] = 0;
                }
            }
        }
        
        if(zero_first_row){
            for(int i = 1; i < ncols; i++){
                matrix[0][i] = 0;
            }
        }
        
        if(zero_first_col){
            for(int i = 1; i < nrows; i++){
                matrix[i][0] = 0;
            }
        }
    }
};
