class Solution {
private:
    vector<vector<int> > result;
    vector<int> num;
    
    void combinationSum2(vector<int> combination, int current, int target, int index){
        if(current == target and combination.size() > 0){
            result.push_back(combination);       
        }
        
        else if(index < num.size()){
            if(current + num[index] > target) return;
            
            int num_repetitions = 1;
            
            while(index + 1 < num.size() and num[index] == num[index + 1]){
                index ++; num_repetitions ++;
            }
            
            combinationSum2(combination,current,target,index + 1);
            
            for(int i = 1; i <= num_repetitions; i++){
                combination.push_back(num[index]);
                current += num[index];
                combinationSum2(combination,current,target,index + 1);
            }
        }
    }
    
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        
        this->result.clear(); this->num.clear();
        sort(num.begin(), num.end());
        this->num = num;
        
        vector<int> t;
        combinationSum2(t,0,target,0);
        return result;
    }
};
