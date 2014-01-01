class Solution {
private:
    string prefix(string &one, string &two){
        int len = 0;
        
        while(len < one.size() and len < two.size()){
            if(one[len] == two[len]){
                len ++;
            } else {
                break;
            }
        }
        
        return one.substr(0,len);
    }
    
public:
    string longestCommonPrefix(vector<string> &strs) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        
        if(strs.size() == 0) return "";
        else if(strs.size() == 1) return strs[0];
        
        string str = strs[0];
        for(int i = 1; i < strs.size(); i++){
            str = prefix(str,strs[i]);
        }
        
        return str;
    }
};
