#define vi vector<int>
#define vii vector<vector<int> >
class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        sort(S.begin(), S.end());
        int n = S.size();
        vii result;
        vi trace;
        dfs(S, 0, n-1, trace, result);
        return result;
    }
    
    void dfs(vector<int> &S, int a, int b, vi &trace, vii &result) {
        result.push_back(trace); //pre-order
        for (int i = a; i <= b; i++) {
            trace.push_back(S[i]);
            dfs(S, i+1, b, trace, result);
            trace.pop_back();
        }
    }
};