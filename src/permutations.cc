class Solution {
private:
    vector<vector<int> > result;
    
    void permute_helper(vector<int> &num, int curr){
        
        if(curr == num.size() - 1){
            vector<int> l = num;
            result.push_back(l);
        } else{
            
            for(int i = curr; i < num.size(); i++){
                
                int temp = num[curr];
                num[curr] = num[i];
                num[i] = temp;
                
                permute_helper(num,curr + 1);
                
                temp = num[curr];
                num[curr] = num[i];
                num[i] = temp;
            }
        }
    }
    
public:
    vector<vector<int> > permute(vector<int> &num) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        
        result.clear();
        permute_helper(num,0);
        return result;
    }
};
