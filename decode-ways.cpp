class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        if (n == 0 || s[0] == '0') 
            return 0;
        //circular buffer;
        int nd[3] = {1, 1, 0};
        int i;
        //gather operation
        for (i = 2; i <= n ; i++) {
            int v = stoi(s.substr(i-2, 2));
            if (v == 0){
                return 0;
            } 
            else if (v >= 1 && v <= 9){ 
                nd[i%3] = nd[(i-1)%3];
            } // 00 01 02 03 04 05 06 07 08 09
            else if (v == 10 || v == 20) {
                nd[i%3] = nd[(i-2)%3];
            }
            else if (v >= 11 && v <= 26){
                nd[i%3] = nd[(i-1)%3] + nd[(i-2)%3];
            }
            else if (v % 10 == 0){ // 30 40 50 60 70 80 90
                nd[i%3] = 0;
            }
            else{
                nd[i%3] = nd[(i+2)%3];
            }
        }
        return nd[(i-1)%3];
    }
};