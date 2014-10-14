class Solution {
public:
    vector<vector<string> > partition(string s) {
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
        
        vector<vector<vector<int> > > pSoFar(n+1);
        pSoFar[0] = {{0}};
        for (int i = 0; i < n; i++){
            for (int j = 0; j < nexts[i].size(); j++){
                for (int k = 0; k < pSoFar[i].size(); k++){
                    vector<int> vpass = pSoFar[i][k];
                    vpass.push_back(nexts[i][j]);
                    pSoFar[nexts[i][j]].push_back(vpass);
                }
            }
        }
        
        int nr =  pSoFar[n].size();
        vector<vector<string> > result(nr);
        for (int i = 0; i < pSoFar[n].size(); i++){
            for (int j = 0; j < pSoFar[n][i].size()-1; j++){
                int a = pSoFar[n][i][j];
                int b = pSoFar[n][i][j+1];
                result[i].push_back(s.substr(a, b - a));
            }
        }
        
        return result;
    }
};