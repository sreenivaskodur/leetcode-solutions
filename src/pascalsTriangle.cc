class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        
        vector<vector<int> > result;
        
        if(numRows == 0) return result;
        
        vector<int> first_row(1,1);
        result.push_back(first_row);
        
        for(int i = 1; i < numRows; i++){
            vector<int> next_row(result[result.size() - 1].size() + 1,1);
            
            for(int j = 0; j < result[result.size() - 1].size() - 1; j++){
                next_row[j + 1] = result[result.size() - 1][j] + result[result.size() - 1][j + 1];
            }
            
            result.push_back(next_row);
        }
        
        return result;
    }
};
