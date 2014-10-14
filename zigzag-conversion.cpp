class Solution {
public:
    string convert(string s, int nRows) {
        string result = "";
        vector<string> storage(nRows);
        int m = s.length();
        if (nRows == 1) 
            return s;
        int pageSize = 2*(nRows-1);
        for (int i = 0; i < m; i += pageSize){
            for (int j = 0; j <= nRows - 2 && (i + j) < m; j++){
                storage[j] += s[i + j];
            }
            for (int j = nRows - 1; j >=1 && (i - j + pageSize) < m; j--){
                storage[j] += s[i - j + pageSize];
            }
        }
        for (string &s : storage){
            result += s;
        }
        return result;
    }
};