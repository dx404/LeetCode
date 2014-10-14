class Solution {
public:
    vector<vector<char> > board;
    vector<vector<bool> > board_visited;
    size_t m, n, t;
    string word;
    bool exist(vector<vector<char> > &board, string word) {
        m = board.size();
        n = board[0].size();
        t = word.size();
        this->board = board;
        this->board_visited = vector<vector<bool> >(m);
        this->word = word;
        fill(board_visited.begin(), board_visited.end(), vector<bool>(n, false));
        for (int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                bool isFound = ExistFrom(i, j, 0);
                if (isFound) return true;
            }
        }
        return false;
    }
    
    bool ExistFrom(int i, int j, int k){
        if (k == t){
            return true;
        }
        if (i < 0 || j < 0 ||
            i >= m || j >= n ||
            board_visited[i][j] ||
            board[i][j] != word[k] ){
            return false;
        }
        board_visited[i][j] = true;
        bool isFound = 
            ExistFrom(i, j+1, k+1) ||
            ExistFrom(i+1, j, k+1) ||
            ExistFrom(i, j-1, k+1) ||
            ExistFrom(i-1, j, k+1) ;
        board_visited[i][j] = false;
        return isFound;
        
    }
};