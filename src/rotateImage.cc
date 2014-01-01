class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        
        int start = 0, end = matrix.size() - 1;
        
        while(end > start){
            
            for(int i = 0; i < end - start; i++){
                int temp = matrix[start][start + i];
                
                matrix[start][start + i] = matrix[end - i][start];
                matrix[end - i][start] = matrix[end][end - i];
                matrix[end][end - i] = matrix[start + i][end];
                matrix[start + i][end] = temp;
            }
            
            start ++; end --;
        }
    }
};
