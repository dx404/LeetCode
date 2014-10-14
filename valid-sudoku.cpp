class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        //row check
        int m = board.size(), n = board[0].size();
        for (auto &row : board){
            set<char> nums;
            for (char c : row){
                if (c == '.') continue; 
                if (nums.count(c) > 0) return false;
                else nums.insert(c);
            }
        }
        //colum check
        for (int j = 0; j < n; j++){
            set<char> nums;
            for (int i = 0; i < m; i++){
                char c = board[i][j];
                if (c == '.') continue; 
                if (nums.count(c) > 0) return false;
                else nums.insert(c);
            }
        }
        //block check
        for (int bi = 0; bi < 9; bi += 3){
            for (int bj = 0; bj < 9; bj += 3){
                set<char> nums;
                for (int i = bi; i < bi + 3; i++){
                    for (int j = bj; j < bj + 3; j++){
                        char c = board[i][j];
                        if (c != '.') {
                            if (nums.count(c) > 0) 
                                return false;
                            else
                                nums.insert(c);
                        } 
                    }
                }
            }
        }
        return true;
    }
};