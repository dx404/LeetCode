class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        int m = triangle.size();
        if (m == 0) return 0;
        vector<int> board (m + 1, numeric_limits<int>::max());
        board[1] = triangle[0][0];
        for (int i = 1; i < m; i++){
            for (int j = i + 1; j >= 1; j--){
                board[j] = min(board[j], board[j-1]) + triangle[i][j-1];
            }
        }
        return *min_element(board.begin(), board.end());
    }
};