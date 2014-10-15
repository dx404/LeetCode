class Solution {
public: //odd-even center expansion
    string longestPalindrome(string s) {
        int n = (int) s.length();
        if (n == 0) return "";
        int start = -1, d = 0, lenMax = -1;
        for (int i = 0; i < n; i++) {
            for (d = 0; i-d >= 0 && i+1+d<=n-1 && s[i-d]==s[i+1+d]; d++);
            if (2*d > lenMax){
                lenMax = 2*d;
                start = i-d+1;
            }
            for (d = 0; i-d >= 0 && i+d<=n-1 && s[i-d]==s[i+d]; d++);
            if (2*d-1 > lenMax){
                lenMax = 2*d-1;
                start = i-d+1;
            }
        }
        return s.substr(start, lenMax);
    }
};
