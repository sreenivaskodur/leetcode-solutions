class Solution {
public:
    void nextPermutation(vector<int> &num) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        
        for(int i = num.size() - 2; i >= 0; i--){
            
            if(num[i + 1] > num[i]){
                
                for(int j = num.size() - 1; j > i; j--){
                    if(num[j] > num[i]){
                        int temp = num[i];
                        num[i] = num[j];
                        num[j] = temp;
                        reverse(num.begin() + i + 1,num.end());
                        return;
                    }
                }
            }
        }
        
        reverse(num.begin(),num.end());
    }
};
