class Solution {
public:
    int min(int n1, int n2){
        return (n1 > n2) ? n2 : n1;
    }
    
    string longestPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        string temp_string = "";
        for(int i = 0; i < s.size(); i++)
            temp_string = temp_string + "#" + s[i];
            
        temp_string = temp_string + "#";
            
        int mid = 0, right = 0;
        
        vector<int> palindrome_length(temp_string.size(),0);
        
        int max = 0;
        int index = 0;
        
        for(int curr = 1; curr < temp_string.size(); curr++){
            
            int mirror = 2 * mid - curr;
            
            palindrome_length[curr] = (right > curr) ? min(palindrome_length[mirror], right - curr) : 0;
            
            while(palindrome_length[curr] + curr + 1 < temp_string.size() and
                  curr - palindrome_length[curr] - 1 >= 0 and
                  temp_string[palindrome_length[curr] + curr + 1] == temp_string[curr - palindrome_length[curr] - 1]){
                      
                  palindrome_length[curr] ++;
            }
            
            if(palindrome_length[curr] + mid > right){
                mid = curr;
                right =  palindrome_length[curr] + curr;
            }
        
            if(palindrome_length[curr] > max){
                max = palindrome_length[curr];
                index = curr;
            }
        }
        
        string ret = "";
        for(int i = index - palindrome_length[index]; i <= index + palindrome_length[index]; i++){
            ret = (temp_string[i] == '#') ? ret : ret + temp_string[i];
        }
        
        return ret;
    }
};
