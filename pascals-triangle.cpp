class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > pt;
        for (int i = 0; i < numRows; i++){
            vector<int> v(i+1, 1);
            for (int j = 1; j <= i - 1; j++){
                v[j] = pt[i-1][j-1] + pt[i-1][j];
            }
            pt.push_back(v);
        }
        return pt;
    }
};