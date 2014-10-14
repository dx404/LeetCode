class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        int n = s.size();
        vector<bool> memo(n);
        for (int i = 0; i < n; i++){
            memo[i] = false;
            if (dict.count(s.substr(0, i + 1)) > 0) {
                 memo[i] = true;
            }
            for (int j = i; j >= 1; j--){
                if (memo[j-1] && dict.count(s.substr(j, i - j + 1)) > 0){
                    memo[i] = true;
                    break;
                }
            }
        }
        return memo[n-1];
    }
};