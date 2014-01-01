class Solution {
private:
    vector<vector<bool> > explored;
    vector<vector<char> > board;
    string word;
    
    bool exist(int row, int col, int curr){
        if(curr == word.size()){return true;}
        
        bool result = false;
        
        if(col > 0 and !explored[row][col - 1] and board[row][col - 1] == word[curr]){
            explored[row][col - 1] = true;
            result = exist(row,col - 1,curr + 1);            
        }
                
        if(!result and (col + 1 < board[0].size()) and !explored[row][col + 1] and board[row][col + 1] == word[curr]){
            explored[row][col + 1] = true;
            result = exist(row,col + 1,curr + 1);
        }
                
        if(!result and row > 0 and !explored[row - 1][col] and board[row - 1][col] == word[curr]){
            explored[row - 1][col] = true;
            result = exist(row - 1,col,curr + 1);
        }
                
        if(!result and (row + 1 < board.size()) and !explored[row + 1][col] and board[row + 1][col] == word[curr]){
            explored[row + 1][col] = true;
            result = exist(row + 1,col,curr + 1);
        }
        
        explored[row][col] = false;
        return result;
    }
    
public:
    bool exist(vector<vector<char> > &board, string word) {
        
        if(word.size() == 0) return true;
        else if(board.size() == 0 and word.size() > 0) return false;
        
        vector<vector<bool> > explored(board.size(),vector<bool>(board[0].size(),false));
        this->explored = explored;
        this->board = board;
        this->word = word;
        
        for(int r = 0; r < board.size(); r++){
            for(int c = 0; c < board[0].size(); c++){
                if(board[r][c] == word[0]){
                    this->explored[r][c] = true;
                    if(exist(r,c,1)) return true;
                    this->explored[r][c] = false;
                }
            }
        }
        
        return false;
    }
};
