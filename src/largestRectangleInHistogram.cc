class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
     
        if(height.size() == 0) return 0;
        else if(height.size() == 1) return height[0];
        
        vector<int> width(height.size(),1);
        stack<int> s;
        
        int curr = 0;
        
        while(curr < height.size()){
            
            while(s.size() > 0 and height[s.top()] > height[curr]){
                width[s.top()] = (curr - s.top());
                s.pop();
            }
            
            if(height[curr] > 0)
                s.push(curr);
                
            curr++;
        }
        
        while(s.size() > 0){
            width[s.top()] = curr - s.top();
            s.pop();
        }
        
        reverse(height.begin(),height.end());
        reverse(width.begin(),width.end());
        
        curr = 0;
        while(curr < height.size()){
            
            while(s.size() > 0 and height[s.top()] > height[curr]){
                width[s.top()] += (curr - s.top() - 1);
                s.pop();
            }
            
            if(height[curr] > 0)
                s.push(curr);
            else
                width[curr] = 0;
                
            curr++;
        }
        
        while(s.size() > 0){
            width[s.top()] += (curr - 1 - s.top());
            s.pop();
        }
        
        int max_rect = height[0] * width[0];
        
        for(int i = 1; i < height.size(); i++){
            max_rect = (max_rect > height[i] * width[i]) ? max_rect : height[i] * width[i];
        }
        
        return max_rect;
    }
};
