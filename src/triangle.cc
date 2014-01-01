class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        
        int h = triangle[triangle.size() - 1].size();
        
        for(int row = h - 2; row >= 0; row--){
            
            for(int i = 0; i < triangle[row].size(); i++){
                
                triangle[h - 1][i] = triangle[row][i] + ((triangle[h - 1][i] > triangle[h - 1][i + 1])?
                                                      triangle[h - 1][i + 1] : triangle[h - 1][i]);
            }
        }
        
        return triangle[h - 1][0];
    }
};
