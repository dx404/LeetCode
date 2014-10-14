class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
        while (--n){
            stringstream ss;
            char memo = 's';
            int count = 0;
            s += "e";
            for (char c : s) {
                if (c == memo) {
                    count++;
                }
                else {
                    if (count)
                        ss << count << memo;
                    memo = c;
                    count = 1;
                }
            }
            ss >> s;
        }
        return s;
    }
};