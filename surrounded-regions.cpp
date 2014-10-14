class Solution {
public:
    // using bfs
    int m, n;
    void solve(vector<vector<char> > &board) {
        // mark to 'Y'
        m = (int) board.size();
        if (m == 0)
            return;
        n = (int) board[0].size();
        if (n == 0)
            return;
        
        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O')
                bfs(board, i, 0);
            if (board[i][n-1] == 'O')
                bfs(board, i, n-1);
        }
        
        for (int j = 1; j <= n - 2; j++){
            if (board[0][j] == 'O')
                bfs(board, 0, j);
            if (board[m-1][j] == 'O')
                bfs(board, m-1, j);
        }
        
        // flip
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
                else if (board[i][j] == 'Y') {
                    board[i][j] = 'O';
                }
            }
        }
    }
    
    void bfs(vector<vector<char> > &board, int i, int j){
        queue<pair<int, int> > q;
        map<pair<int, int>, int> visited;
        
        q.push({i, j});
        visited[{i, j}]++;
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            board[x][y] = 'Y';
            
            if (x+1 < m && (visited.count({x+1,y}) == 0 || visited[{x+1,y}] == 0) && board[x+1][y] == 'O'){
                q.push({x+1, y});
                visited[{x+1, y}]++;
            }

            if (y+1 < n && (visited.count({x,y+1}) == 0 || visited[{x,y+1}] == 0) && board[x][y+1] == 'O'){
                q.push({x, y+1});
                visited[{x, y+1}]++;
            }

            if (x >= 1 && (visited.count({x-1,y}) == 0 || visited[{x-1,y}] == 0) && board[x-1][y] == 'O'){
                q.push({x-1, y});
                visited[{x-1, y}]++;
            }

            if (y >= 1 && (visited.count({x,y-1}) == 0 || visited[{x,y-1}] == 0) && board[x][y-1] == 'O'){
                q.push({x, y-1});
                visited[{x, y-1}]++;
            }

        }
    }
};