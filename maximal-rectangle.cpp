class Solution {
public:
    vector<pair<int, int> > memoLeft, memoRight;
    
    int maximalRectangle(vector<vector<char> > &matrix) {
        int m = (int) matrix.size();
        if (m == 0) 
            return 0;
        int n = (int) matrix[0].size();
        if (n == 0)
            return 0;
        
        int maxArea = 0;
        vector<int> hist(n, 0);
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                hist[j] = (matrix[i][j] == '0') ? 0 : hist[j] + 1;  
            }
            maxArea = max(maxArea, largestRectangleArea(hist));
        }
        return maxArea;
    }
    
    int largestRectangleArea(vector<int> &bar){
        int n = (int) bar.size();
        vector<int> left(n), right(n);
        
        memoLeft.push_back({-1, -1});
        for (int i = 0; i < n; i++) {
            int x = bar[i];
            while(x <= memoLeft.back().first){
                memoLeft.pop_back();
            }
            left[i] = memoLeft.back().second + 1;
            memoLeft.push_back({x, i});
        }
        
        memoRight.push_back({-1, n});
        for (int i = n - 1; i >= 0; i--) {
            int x = bar[i];
            while(x <= memoRight.back().first){
                memoRight.pop_back();
            }
            right[i] = memoRight.back().second - 1;
            memoRight.push_back({x, i});
        }
        
        int maxSoFar = 0;
        for (int i = 0; i < n; i++) {
            maxSoFar = max(maxSoFar, (right[i] - left[i] + 1) * bar[i]);
        }
        return maxSoFar;
    }
};
