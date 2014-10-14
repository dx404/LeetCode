class Solution {
public:
    double pow(double x, int n) {
        if (x == 0 || x == 1) return x;
        if (x < 0) return pow(-x, n) * (n & 1 ? -1 : 1);
        if (n == 0) return 1;
        if (n < 0) return 1/pow(x, -n);

        double hv = pow(x, n/2); 
        return hv * hv * (n & 1 ? x : 1);
        
    }
};