typedef struct{
    int number;
    int index;
}entry;

bool operator <(entry one, entry two){
        return one.number < two.number;
}

class Solution {
private:
    vector<entry> vals;
    int target;
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        vector<entry> vals(0);
        
        for(int i = 0; i < numbers.size(); i++){
            entry e;
            e.number = numbers[i];
            e.index = i + 1;
            
            vals.push_back(e);
        }
        
        this->vals = vals;
        sort(this->vals.begin(),this->vals.end());
        this->target = target;
        
        return helperTwoSum();
    }
    
    vector<int> helperTwoSum(){
        
        int length = vals.size();
        
        int index_one = 0, index_two = length - 1;
        
        while(index_one < length and index_two >= 0){
            
            if(index_one == index_two) index_one ++;
            
            else if(vals[index_one].number + vals[index_two].number == target){
                vector<int> soln(2);
                
                if(vals[index_one].index < vals[index_two].index){
                    soln[0] = vals[index_one].index;
                    soln[1] = vals[index_two].index;
                }
                
                else{
                    soln[0] = vals[index_two].index;
                    soln[1] = vals[index_one].index;
                }
                
                return soln;
            }
            
            else if(vals[index_one].number < target - vals[index_two].number) index_one ++;
            else index_two --;
        }
    }
};
