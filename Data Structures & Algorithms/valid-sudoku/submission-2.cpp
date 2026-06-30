class Solution {
public:

    bool isValid(vector<vector<char>> &board, int row, int col, char val){
        for(int i = 0; i < 9; i++){
            if(i != row && board[i][col] == val){
                return false;
            }
        }

        for(int j = 0; j < 9; j++){
            if(j != col && board[row][j] == val){
                return false;
            }
        }

        int startRow = row - (row%3);
        int startCol = col - (col%3);
        
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(row == startRow + i && col == startCol + j) continue;
                if(board[i+startRow][j+startCol] == val) return false;
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] == '.') continue;
                if(isValid(board, i, j, board[i][j]) == false){
                    return false;
                }
            }
        }
        return true;
    }
};
