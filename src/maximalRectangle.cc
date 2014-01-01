class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        
        if(matrix.size() == 0) return 0;
        
        vector<vector<int> > aux_height(matrix.size(), vector<int>(matrix[0].size(),0));
        vector<vector<int> > aux_width(matrix.size(), vector<int>(matrix[0].size(),0));
        
        int rows = matrix.size(), cols = matrix[0].size();
        
        for(int r = rows - 1; r >= 0; r--){
            for(int c = cols - 1; c >= 0; c--){
                if(matrix[r][c] == '1'){
                    aux_width[r][c] = ((c == cols - 1) ? 1 : aux_width[r][c + 1] + 1);
                    aux_height[r][c] = ((r == rows - 1) ? 1 : aux_height[r + 1][c] + 1);
                }
            }
        }
        
        int max_area = 0;
        
        for(int r = 0; r < rows; r++){
            for(int c = 0; c < cols; c++){
                if(matrix[r][c] == '1'){
                    int min_height = aux_height[r][c];
                    int min_width = aux_width[r][c];
                    
                    int ma = (aux_width[r][c] > min_height) ? aux_width[r][c] : min_height;
                    
                    for(int ci = c + 1; ci < c + aux_width[r][c]; ci++){
                        min_height = (aux_height[r][ci] > min_height) ? min_height : aux_height[r][ci];
                        int width = ci - c + 1;
                        ma = (min_height * width > ma) ? min_height * width : ma;
                    }
                    
                    max_area = (max_area < ma) ? ma : max_area;
                }
            }
        }
        
        return max_area;
    }
};
