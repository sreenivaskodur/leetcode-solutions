class Solution {
private:
    map<int,int> lookup_table;
    
public:
    int climbStairs(int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        
        if(n == 1) return 1;
        else if(n == 2) return 2;
        
        int curr_minus_2 = 1, prev = 2,result = 0;
        for(int i = 3; i <= n; i++){
            result = prev + curr_minus_2;
            curr_minus_2 = prev;
            prev = result;
        }
        
        return result;
    }
};
