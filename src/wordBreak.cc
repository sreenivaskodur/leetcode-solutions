class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        
        if(s.size() == 0) return false;
        else if(s.size() == 1) return dict.find(s) != dict.end();
        
        vector<bool> can_be_segmented(s.size() + 1,false);
        
        can_be_segmented[0] = true;
        
        for(int i = 1; i <= s.size(); i++){
            for(int j = 0; j < i; j++){
                if(can_be_segmented[j] and dict.find(s.substr(j,i - j)) != dict.end()){
                    can_be_segmented[i] = true;
                }
            }
        }
        
        return can_be_segmented[s.size()];
    }
};