class Solution {
private:
    double pow_helper(double x, int n){
        if(n == 0) return 1.0;
        
        else if(n % 2 == 0){
            double r = pow_helper(x,n / 2);
            return r * r;
        } else{
            double r = pow_helper(x,n / 2);
            return r * r * x;
        }
    }
    
public:
    double pow(double x, int n) {
        
        if(n == 0) return 1.0;
        
        if(n > 0){
            return pow_helper(x,n);
        } else{
            return 1.0 / pow_helper(x,-1 * n);
        }
    }
};
