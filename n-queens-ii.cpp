class Solution {
public:
    int n;
    int wMask;
    int totalNQueens(int n) {
        this->n = n;
        this->wMask = (1<<n)-1;
        return run(0, 0, 0, n);
    }
private:
    int run(int left, int down, int right, int level){
        if (level == 0) return 1;
        
        int total = 0;
        int pos = (left | down | right) & wMask;
        if (pos == wMask) return 0;
        
        for (int i = 0; i < n; i++){
            int setbit = (1 << i);
            if ((pos & setbit) != 0)
                continue;
            total += run((left|setbit) << 1, down|setbit, (right | setbit)>>1, level - 1);
        }
        return total;
    }
};