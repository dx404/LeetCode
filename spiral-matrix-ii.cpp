class Solution {
public:
    void mfill(vector<vector<int> > &a, int val, int low, int high){
        if (low == high) {
            a[low][high] = val;
            return;
        }
        if (low > high){
            return;
        }
        
        for (int j = low; j <= high - 1; j++) {
            a[low][j] = val++;
        }
        for (int i = low; i <= high - 1; i++) {
            a[i][high] = val++;
        }
        for (int j = high; j >= low + 1; j--) {
            a[high][j] = val++;
        }
        for (int i = high; i >= low + 1; i--) {
            a[i][low] = val++;
        }
        mfill(a, val, low + 1, high - 1);
    }
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > a;
        for (int i = 0; i < n; i++) {
            a.push_back(vector<int>(n, -1));
        }
        mfill(a, 1, 0, n-1);
        return a;
    }
};
