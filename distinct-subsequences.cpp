class Solution {
public:
    int numDistinct(string S, string T) {
        size_t nt = T.size();
        vector<int> board(nt+1, 0);
        board[0] = 1;
        for (auto c : S){
            for (size_t i = nt; i >= 1; --i){
                if (c == T[i-1]) 
                    board[i] += board[i-1];
            }
        }
        return board[nt];
    }
};