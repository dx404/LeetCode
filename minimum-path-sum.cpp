class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        int m = (int) grid.size();
        int n = (int) grid[0].size();
        for (int s = 1; s < m + n - 1; s++){
            for (int j = max(0, s - m + 1); j < min(n,s+1); j++){
                int i = s - j;
                int lMin = (i > 0)? grid[(i-1)][j] : (1 << 31) - 1;
                int uMin = (j > 0)?  grid[i][j-1] : (1 << 31) - 1;
                grid[i][j] += min(lMin, uMin);
            }
        }
        return grid[m-1][n-1];
    }
};