class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        
        sort(num.begin(),num.end());
        
        int min_dev = INT_MAX, sum;
        
        for(int i = 0; i < num.size(); i++){
            
            int start = i + 1, end = num.size() - 1;
            
            while(start < end){
                int curr_sum = num[i] + num[start] + num[end];
                
                if(curr_sum == target){
                    return target;
                } else if(curr_sum < target){
                    if(target - curr_sum < min_dev){
                        min_dev = target - curr_sum;
                        sum = curr_sum;
                    }
                    
                    start ++;
                } else{
                    if(curr_sum - target < min_dev){
                        min_dev = curr_sum - target;
                        sum = curr_sum;
                    }
                    
                    end --;
                }
            }
            
            while(i < num.size() - 1 and num[i] == num[i + 1]) i++;
        }
        
        return sum;
    }
};
