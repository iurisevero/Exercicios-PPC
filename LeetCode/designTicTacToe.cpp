class TicTacToe {
public:
    // Win conditions: complete row, complete column or complete diagonal
    // space complexity can be improved by using vector or dynamic allocation
    int board[100][100];
    int boardSize;
    // use to block moves after someone wins
    int winner;

    TicTacToe(int n) {
        boardSize = n;
        winner = -1;
    }
    
    int move(int row, int col, int player) {
        if(winner == -1){
            // make the move
            board[row][col] = player;
            // check if this move make the player win
            bool win = checkVictory(row, col, player);
            // cout << "Player " << player << ": " << win << endl;
            if(win){  
                return winner = player;
            }
            return 0;
        }
        // If a winner exists, return him
        return winner;
    }
    
    // Check the 3 victory conditions
    bool checkVictory(int row, int col, int player){
        return checkRol(row, player) || checkCol(col, player) || checkDiagonal(row, col, player);
    }
    
    // O(n)
    bool checkRol(int row, int player){
        // all columns of the row have to be equal to player
        for(int i=0; i < boardSize; ++i){
            if(board[row][i] != player){
                return false;
            }
        }
        return true;
    }
    
    // O(n)
    bool checkCol(int col, int player){
        // all rows of the col have to be equal to player
        for(int i=0; i < boardSize; ++i){
            if(board[i][col] != player){
                return false;
            }
        }
        return true;
    }
    
    // O(2 * n)
    bool checkDiagonal(int row, int col, int player){
        // main diagonal i == j
        // secondary diagonal i + j == boardSize
        // if not satisfied, (row, col) is not a valid diagonal
        if(row == col || row + col == boardSize - 1){
            bool win = true;
            // check main diagonal O(n)
            for(int i=0; i < boardSize; ++i){
                if(board[i][i] != player){
                    win = false;
                    break;
                }
            }
            // main diagonal results true
            if(win) return win;
            
            // check secondary diagonal O(n)
            win = true;
            for(int i=0; i < boardSize; ++i){
                // secondary diagonal i + j == boardSize
                // j = boardSize - i (- 1 cause the count starts at 0)
                if(board[i][boardSize - i - 1] != player){
                    win = false;
                    break;
                }
            }
            return win;
        }
        return false;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */