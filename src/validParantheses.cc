class Solution {
public:
    bool isValid(string s) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        
        if(s.size() == 0) return true;
        
        stack<char> aux;
        
        aux.push(s[0]);
        int curr = 1;
        
        while(curr < s.size()){
            if(s[curr] == '(' or s[curr] == '{' or s[curr] == '['){
                aux.push(s[curr]);
            }
            
            else if(aux.size() > 0 and ((s[curr] == ')' and aux.top() == '(') or
                     (s[curr] == '}' and aux.top() == '{') or (s[curr] = ']' and aux.top() == '['))){
                         aux.pop();
            }
            
            else return false;
            
            curr ++;
        }
        
        return aux.empty();
    }
};
