class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        if(tokens.size() == 0) return 0;
        
        stack<int> s;
        int value = atoi(tokens[0].c_str());
        s.push(value);
        
        int curr = 1;
        while(curr < tokens.size()){
            
            if(tokens[curr].size() == 1){
                switch(tokens[curr].c_str()[0]){
                    case '+':
                    {
                        int n = s.top();
                        s.pop();
                        value = s.top() + n;
                        s.pop(); s.push(value); break;
                    }
                    case '/':
                    {
                        int n = s.top();
                        s.pop();
                        value = s.top() / n;
                        s.pop(); s.push(value); break;
                    }
                    case '*':
                    {
                        int n = s.top();
                        s.pop();
                        value = s.top() * n;
                        s.pop(); s.push(value); break;
                    }
                    case '-':
                    {
                        int n = s.top();
                        s.pop();
                        value = s.top() - n;
                        s.pop(); s.push(value); break;
                    }
                    default:
                        s.push(atoi(tokens[curr].c_str()));
                }
            }
            
            else{
                s.push(atoi(tokens[curr].c_str()));
            }
            
            curr ++;
        }
        
        return value;
    }
};
