class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result = {""};
        map<char, string> d2c = {
            {'1',""},
            {'2',"abc"},
            {'3',"def"},
            {'4',"ghi"},
            {'5',"jkl"},
            {'6',"mno"},
            {'7',"pqrs"},
            {'8',"tuv"},
            {'9',"wxyz"},
            {'0'," "},
            {'*',"+"},
            {'#',""},
        };
        
        for (char d : digits){
            int m = result.size();
            int n = d2c[d].length();
            result.resize(m * n);
            for (int i = m; i < m * n; i++){
                result[i] = result[i-m];
            }
            for (int j = 0; j < n; j++){
                char c = d2c[d][j];
                for (int i = 0; i < m; i++){
                    result[m*j + i] +=  c;
                }
            }
        }
        return result;
    }
};