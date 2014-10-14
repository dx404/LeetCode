class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        string s = "";
        int m = strs.size(), nMin = INT_MAX;
        if (m == 0){
            return s;
        }
        for (int i = 0; i < strs.size(); i++){
            nMin = min(nMin, (int)strs[i].size());
        }
        for (int j = 0; j < nMin; j++){
            char c = strs[0][j];
            for (int i = 1; i < strs.size(); i++){
                if (c != strs[i][j]){
                    return s;
                }
            }
            s += c;
        }
        return s;
    }
};