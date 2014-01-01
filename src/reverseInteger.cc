class Solution {
public:
    int reverse(int x) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        
        bool is_negative = (x < 0)  ? true : false;
        
        x = (is_negative) ? -1 * x : x;
        
        int result = 0;
        
        while(x > 0){
            result = result * 10 + x % 10;
            x = x / 10;
        }
        
        return (is_negative) ? -1 * result : result;
    }
};
