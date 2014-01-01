class Solution {
private:
    int min(int n1,int n2,int n3){
        int m = n1 > n2 ? n2 : n1;
        m = m > n3 ? n3 : m;
        
        return m;
    }
    
public:
    int minDistance(string word1, string word2) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        
        if(word1.size() == 0) return word2.size();
        else if(word2.size() == 0) return word1.size();
  
        vector<vector<int> > dp(word1.size() + 1,vector<int>(word2.size() + 1,0));
        
        for(int w1 = 1; w1 <= word1.size(); w1++){
            dp[w1][0] = w1;
        }
        
        for(int w2 = 1; w2 <= word2.size(); w2++){
            dp[0][w2] = w2;
        }
        
        for(int w1 = 1; w1 <= word1.size(); w1++){
            for(int w2 = 1; w2 <= word2.size(); w2++){
                if(word1[w1- 1] == word2[w2 - 1]){
                    dp[w1][w2] = dp[w1 - 1][w2 - 1];
                } else{
                    dp[w1][w2] = 1 + min(dp[w1 - 1][w2],dp[w1][w2 - 1],dp[w1 - 1][w2 - 1]);
                }
            }
        }
        
        return dp[word1.size()][word2.size()];
    }
};
