class Solution {
public:
    vector<string> result;
    vector<vector<int> > memo;
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        if (dict.size() == 0){
            return {};
        }
        int n = s.length();
        memo.resize(n);
        for (int i = 0; i < n; i++){
            string si = s.substr(0, i + 1);
            if (dict.count(si) > 0){
                memo[i].push_back(0);
            }
            for (int j = i; j >= 1; j--){
                string right = s.substr(j, i - j + 1);
                if (dict.count(right) > 0 && memo[j-1].size() > 0){
                    memo[i].push_back(j);
                }
            }
            
        }
        trace("", n-1, s);
        return result;
    }
    
    void trace(string pre, int i, string &s){
        if (i < 0){
            result.push_back(pre.substr(0, pre.length() - 1));
            return;
        }
        for (int j : memo[i]){
            trace(s.substr(j, i - j + 1) + " " + pre, j - 1, s);
        }
    }
    
};