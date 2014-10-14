class Solution {
public:
    string justifyLine(vector<string> &tank, int m, int L){
        string s = "";
        int n = tank.size();
        if (n == 1){
            return s = tank[0] + string(L - m, ' ');
        }
        int lowSpace = (L - m) / (n - 1);
        int rCount = (L - m) % (n - 1);
        for (int i = 0; i < n; i++){
            if (i < rCount)
                s += (tank[i] + string(lowSpace + 1, ' '));
            else
                s += (tank[i] + string(lowSpace, ' '));
                
        }
        return s.substr(0, L);
    }
    
    string justifyLastLine(vector<string> &tank, int m, int L){
        string s = "";
        int n = tank.size();
        if (n == 1){
            return s = tank[0] + string(L - m, ' ');
        }
        for (int i = 0; i < n; i++){
            s += (tank[i] + ' ');
        }
        int c = s.length();
        if (c >= L){
            return s.substr(0, L);
        }
        return s + string(L - c, ' ');
    }
    
    vector<string> fullJustify(vector<string> &words, int L) {
        vector<string> sl;
        int m = 0; // words length
        int mw = -1; //words least 
        vector<string> tank;
        for (string w : words){
            int n = w.size();
            if (mw + n >= L) {
                sl.push_back(justifyLine(tank, m, L));
                tank.clear();
                m = 0;
                mw = -1;
            }
            tank.push_back(w);
            m += n;
            mw += (n+1);
        }
        if (m != 0){
            sl.push_back(justifyLastLine(tank, m, L));
        }
        if (sl.size() == 0){
            return {string(L, ' ')};
        }
        return sl;
        
    }
};