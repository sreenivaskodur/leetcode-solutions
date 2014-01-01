struct Number{
    int num;
    Number* prev;
};

class Solution {
private:
    vector<vector<int> > possible_combinations;
    
    void combinationSumHelper(vector<int> &candidates, int curr_index, Number* combination, int target, int curr_sum){
        if(curr_sum == target){
            vector<int> curr_combination;
            
            Number* temp = combination;
            while(temp != NULL){
                curr_combination.push_back(temp->num);
                temp = temp->prev;
            }
            
            reverse(curr_combination.begin(),curr_combination.end());
            possible_combinations.push_back(curr_combination);
        }
        
        else if(curr_index < candidates.size() and target - curr_sum >= candidates[curr_index]){
            Number* curr_num = new Number;
            curr_num->num = candidates[curr_index];
            curr_num->prev = combination;
            
            combinationSumHelper(candidates, curr_index, curr_num, target, curr_sum + candidates[curr_index]);
            combinationSumHelper(candidates, curr_index + 1, combination, target, curr_sum);
        }
    }
    
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        possible_combinations.clear();
        sort(candidates.begin(), candidates.end());
        combinationSumHelper(candidates,0,NULL,target,0);
        return possible_combinations;
    }
};
