class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        
        vector<vector<int> > solns;
        
        if(num.size() == 0) return solns;
        
        sort(num.begin(),num.end());
    
        for(int i = 0; i < num.size() - 1; i++){
            for(int j = i + 1; j < num.size() - 1; j++){
                
                int l = j + 1, r = num.size() - 1;
                int t = target - num[i] - num[j];
                
                while(l < r){
                    if(num[l] + num[r] == t){
                        vector<int> curr_soln;
                        curr_soln.push_back(num[i]);
                        curr_soln.push_back(num[j]);
                        curr_soln.push_back(num[l]);
                        curr_soln.push_back(num[r]);
                        
                        solns.push_back(curr_soln);
                        l++; r--;
                        
                        int n = num[l - 1];
                        while(l < num.size() and num[l] == n){
                            l++;
                        }
                        
                        n = num[r + 1];
                        while(r > j and num[r] == n){
                            r --;
                        }
                    }
                    else if(num[l] + num[r] < t) l++;
                    else r --;
                }
                
                int n = num[j];
                while(j + 1 < num.size() and num[j + 1] == n){
                    j ++;
                }
            }
            
            int n = num[i];
            while(i + 1 < num.size() and num[i + 1] == n){
                i++;
            }
        }
        
        return solns;
    }
};
