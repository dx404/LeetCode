class Solution {
public:
    int minCut(string s) {
        int n = (int) s.length();
        vector<vector<int> > nexts(n+1);
        for (int i = 0; i < n; i++){
            for (int d = 0; (i-d >= 0 && i+d < n); d++){
                if (s[i-d] == s[i+d]) {
                    nexts[i-d].push_back(i+d+1);
                }
                else break;
            }
            for (int d = 0; (i-d >= 0 && i+d < n); d++){
                if (s[i-d] == s[i+1+d]) {
                    nexts[i-d].push_back(i+d+2);
                }
                else break;
            }
        }
        // This version is a quadratic algorithm, subject to reduce to O(1)
        vector<int> nPath(n+1, INT_MAX);
        nPath[0] = 0;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < nexts[i].size(); j++){
                nPath[nexts[i][j]] = min(nPath[nexts[i][j]], nPath[i] + 1);
            }
        }
        
        return  nPath[n] - 1;
    }
};