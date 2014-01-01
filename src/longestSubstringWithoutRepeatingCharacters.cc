class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        vector<int> last_occurence(256,-1);
    
        int start_index = 0, curr_index = 0, max_length = 0;
        
        while(curr_index < s.size()){
            int index = s[curr_index];
            
            if(last_occurence[index] != -1 and last_occurence[index] >= start_index){
                start_index = last_occurence[index] + 1;
            }

            max_length = max_length < (curr_index - start_index + 1) ? curr_index - start_index + 1 : max_length;
            last_occurence[index] = curr_index;            
            curr_index ++;
        }
        
        return max_length;
    }
};
