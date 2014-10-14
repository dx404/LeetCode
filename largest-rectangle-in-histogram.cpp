class Solution {
public:
    vector<pair<int, int> > memoLeft, memoRight;
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