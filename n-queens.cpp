class Solution {
public:
    int n, wMask;
    vector<vector<string> > result;
    vector<vector<string> > solveNQueens(int n) {
        this->n = n;
        this->wMask = (1<<n)-1;
        int total = run(0, 0, 0, n);
        return result;
    }
private:
    int run(int left, int down, int right, int level, vector<string> trace = vector<string>()){
        if (level == 0) {
            result.push_back(trace);
            return 1;
        }
        
        int pos = (left | down | right) & wMask;
        if (pos == wMask) return 0;
        
        int total = 0;
        for (int i = 0; i < n; i++){
            int setbit = (1 << i);
            if ((pos & setbit) != 0)
                continue;
            trace.push_back(toStringRow(i, n));
            total += run((left|setbit) << 1, down|setbit, (right | setbit) >> 1, level - 1, trace);
            trace.pop_back();
        }
        return total;
    }
    
    string toStringRow(int p, int w){
        string s (w, '.');
        s[p] = 'Q';
        return s;
    }
    
};