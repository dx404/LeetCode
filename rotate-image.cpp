class Solution {
    public:
        void rotate(vector<vector<int> > &matrix) {
            int n = (int) matrix.size();
            int hn = (n & 1) ? (n/2+1) : (n/2);
            for (int i = 0; i < hn; i++) {
                for (int j = i; j < n-1-i; j++){
                    int t = matrix[i][j];
                    matrix[i][j] = matrix[n-1-j][i];
                    matrix[n-1-j][i] = matrix[n-i-1][n-j-1];
                    matrix[n-i-1][n-j-1] = matrix[j][n-i-1];
                    matrix[j][n-i-1] = t;
                }
            }
        }
    
};