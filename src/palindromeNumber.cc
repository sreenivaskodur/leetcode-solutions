class Solution {
private:
    bool isPalindromeHelper(int num, int& reverse){
        
        if(num == 0) return true;
        
        if(isPalindromeHelper(num / 10, reverse)){
            
            if(reverse % 10 == num % 10){
               reverse = reverse / 10;
               return true;
            }
            
            return false;
        }
        
        return false;
    }
    
public:
    bool isPalindrome(int x) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        
        if(x < 0) return false;
        return isPalindromeHelper(x,x);
    }
};
