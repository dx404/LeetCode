class Solution {
public:
    string multiply(string s, string t) {
        string r = string(s.size() + t.size(), '0');
        auto kr = r.rbegin();
        for (auto it = s.rbegin(); it != s.rend(); it++){
            for (auto jt = t.rbegin(); jt != t.rend(); jt++){
                int di = distance(s.rbegin(), it);
                int dj = distance(t.rbegin(), jt);
                int de = di + dj;
                int val = (*it - '0')*(*jt - '0') + kr[de]-'0';
                kr[de] =  (val % 10) + '0';
                kr[de+1] +=  (val / 10);
            }
        }
        for (auto kt = r.begin(); kt != r.end(); kt++){
            if (*kt != '0'){
                return string(kt, r.end());
            }
        }
        return "0";
    }
};