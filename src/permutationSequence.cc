class Solution {
private:
    priority_queue<int,vector<int>,std::greater<int> > min_heap;
    
    string getPermutation(int factorial, int k, int n){
        
        vector<int> poped_numbers;
        string result = "";
        
        if(n == 1){
            result = (min_heap.top() + '0');
            min_heap.pop();
            return result;
        }
        
        else if(k == 1){
            while(min_heap.size() > 0){
                result += (min_heap.top() + '0');
                min_heap.pop();
            }
            
            return result;
        }
        
        while(factorial < k){
            poped_numbers.push_back(min_heap.top());
            min_heap.pop();
            k -= factorial;
        }
        
        result = (min_heap.top() + '0');
        min_heap.pop();
        
        for(int i = 0; i < poped_numbers.size(); i++){
            min_heap.push(poped_numbers[i]);
        }
        
        return result + getPermutation(factorial / (n - 1), k, n - 1);
    }
    
public:
    string getPermutation(int n, int k) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        
        for(int i = 1; i <= n; i++){
            min_heap.push(i);
        }
        
        int factorial = 1;
        for(int i = 2; i < n; i++){
            factorial *= i;
        }
        
        return getPermutation(factorial,k,n);
    }
};
