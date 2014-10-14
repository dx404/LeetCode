class Solution {
public:
    map<tuple<int, int>, int> mp;
    int m, n;
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid, int i, int j) {
        tuple<int, int> ij = make_tuple(i, j);
        if (mp.count(ij) > 0){
            return mp[ij];
        }
        if (i == m - 1 && j == n - 1){
            return mp[ij] = obstacleGrid[i][j] == 1 ? 0 : 1;
        }
        if (i > m - 1 || j > n - 1 || obstacleGrid[i][j] == 1){
            return 0;
        }
        int right = uniquePathsWithObstacles(obstacleGrid, i, j + 1);
        int down =  uniquePathsWithObstacles(obstacleGrid, i+1, j);
        return mp[ij] = right + down;
    }
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        m = obstacleGrid.size();
        if (m == 0) {
            return 0;
        }
        n = obstacleGrid[0].size();
        if (n == 0) {
            return 0;
        }
        return uniquePathsWithObstacles(obstacleGrid, 0, 0);
    }
};