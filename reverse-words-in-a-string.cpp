class Solution {
public:
    void reverseWords(string &s) {
        string rs = "";
        int n = (int) s.size();
        int i = 0;
        while (i < n && isspace(s[i])){
            i++;
        }
        while (i < n){
            string w = "";
            while(i < n && !isspace(s[i])){
                w += s[i];
                i++;
            }
            rs = w + " " + rs;
            while(i < n && isspace(s[i])){
                i++;
            }
        
        }
        s = rs.substr(0, rs.size()-1);
    }
};