class Solution {
public:
    vector<vector<int> > result;
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        sort(S.begin(), S.end());
        vector<int> trace;
        dfs(S, 0, trace);
        return result;
    }
    
    void dfs(vector<int> &S, int start, vector<int> &trace) {
        result.push_back(trace);
        int n = S.size();
        int prev = S[start] - 1;
        for (int i = start; i < n; i++) {
            if (S[i] > prev) {
                prev = S[i];
                trace.push_back(S[i]);
                dfs(S, i + 1, trace);
                trace.pop_back();
            } 
        }
    }
};