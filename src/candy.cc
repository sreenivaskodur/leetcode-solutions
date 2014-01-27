class Solution {
public:
    int candy(vector<int> &ratings) {
        if(ratings.size() == 0) return 0;
        
        vector<int> candie_count(ratings.size(),0);
        
        int start = 0, num_candies = ratings.size();
        
        for(int i = 1; i < ratings.size(); i++){
            if(ratings[i - 1] < ratings[i]){
                candie_count[i] = candie_count[i - 1] + 1;
            }
        }
        
        for(int i = ratings.size() - 2; i >= 0; i--){
            if(ratings[i] > ratings[i + 1]){
                candie_count[i] = candie_count[i + 1] + 1;
            } else if(ratings[i] < ratings[i + 1]){
                candie_count[i + 1] = (candie_count[i + 1] > candie_count[i] + 1) ? candie_count[i + 1] : candie_count[i] + 1;
            }
        }
        
        for(int i = 0; i < ratings.size(); i++){
            num_candies += candie_count[i];
        }
        
        return num_candies;
    }
};