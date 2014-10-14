class Solution {
public:
    vector<string> result; // read 1 or 2 or 3 at each step
    string s;
    int n;
    bool vailIPSeg(string s){
        int x = stoi(s);
        return x >= 0 && x <= 255 && to_string(x).size() == s.size();
    }
    void restoreFrom(int start, int seg, string trace){
        if (start >= n || seg >= 4){
            if (start == n && seg == 4){
                result.push_back(trace.substr(1));
            }
            return;
        }
        for (int w = 1; w <= 3; w++){
            string word = s.substr(start, w);
            if (vailIPSeg(word))
                restoreFrom(start + w, seg + 1, trace + "." + word) ;
        }
    }
    
    vector<string> restoreIpAddresses(string s) {
        this->s = s;
        this->n = s.length();
        restoreFrom(0, 0, "");
        return result;
    }
};
