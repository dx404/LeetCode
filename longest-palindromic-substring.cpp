
class Solution {
public:
    string longestPalindrome(string s) {
        string result  = s;
        int n = (int) s.length();
        if (n <= 0) return "";
        int start = -1, end = n, dmax = -1;
        for (int i = 0; i < n; i++) {
            int d;
            for (d = 0; i + d + 1 < n && i - d >= 0; d++){
                if (s[i-d] != s[i+d+1]){
                    break;
                }
            }
            d--;
            if (d > dmax){
                dmax = d;
                start = i - d;
                end = i + d + 1;
            }
        }
        
        for (int i = 0; i < n; i++) {
            int d;
            for (d = 0; i + d < n && i - d >= 0; d++){
                if (s[i-d] != s[i+d]){
                    break;
                }
            }
            d--;
            if (d > dmax){
                dmax = d;
                start = i - d;
                end = i + d;
            }
        }
        result = s.substr(start, end - start + 1);
        return result;
    }
};