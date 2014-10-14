class Solution {
public:
    void solveSudoku(vector<vector<char> > &board) {
        solveSudokuNext(board);
    }
    
    bool solveSudokuNext(vector<vector<char> > &board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++){
                if (board[i][j] != '.') 
                    continue;
                for (int k = 1; k <= 9; k++){
                    board[i][j] = '0' + k;
                    if (isValidSudoku(board, i, j) && solveSudokuNext(board)) {
                        return true;
                    }
                    board[i][j] = '.';
                }
                return false;
                
            }
        }
        return true;
    }
    
    bool isValidSudoku(vector<vector<char> > &board, int x, int y) {
        for (int i = 0; i < 9; i++){
            if (i != x && board[i][y] == board[x][y]){
                return false;
            }
        }
        
        for (int j = 0; j < 9; j++) {
            if (j != y && board[x][j] == board[x][y]) {
                return false;
            }
        }
        
        int bx = x/3, by = y/3;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if ((3*bx + i != x || 3*by + j != y) && (board[3*bx + i][3*by + j] == board[x][y])){
                    return false;
                }
            }
        }
        return true;
    }
};