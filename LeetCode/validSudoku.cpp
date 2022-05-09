// 24 ms 17.8MB
class Solution {
public:  
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0; i < 9; ++i){
            for(int j=0; j < 9; ++j){
                if(board[i][j] != '.'){
                    // validade row
                    for(int k=0; k < 9; ++k){
                        if(k == j) continue;
                        if(board[i][k] == board[i][j]) return false;
                    }
                    
                    // validade row
                    for(int k=0; k < 9; ++k){
                        if(k == i) continue;
                        if(board[k][j] == board[i][j]) return false;
                    }
                }       
            }
        }
        
        for(int i=3; i <= 9; i += 3){
            for(int j=3; j <= 9; j += 3){
                int valid[9] = {0};
                for(int k=i-3; k < i; ++k){
                    for(int l=j-3; l < j; ++l){
                        if(board[k][l] != '.'){
                            int numb = board[k][l] - '0' - 1;
                            valid[numb]++;
                            if(valid[numb] > 1) return false;
                        }
                    }
                }       
            }
        }
        return true;
    }
};