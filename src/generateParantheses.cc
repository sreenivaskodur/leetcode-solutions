class Solution {
private:
    vector<string> all_parenthesis;
    int n;
    
    void generateParenthesis_helper(int num_open, int num_closed, string s){
        if(num_open == n and num_closed == n){
            all_parenthesis.push_back(s);
            return;
        }
        
        if(num_open < n){
            generateParenthesis_helper(num_open + 1,num_closed,s + "(");
        }
        
        if(num_closed < num_open){
            generateParenthesis_helper(num_open,num_closed + 1,s + ")");
        }
    }
    
public:
    vector<string> generateParenthesis(int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        
        all_parenthesis.clear();
        this->n = n;
        generateParenthesis_helper(0,0,"");
        return all_parenthesis;
    }
};
