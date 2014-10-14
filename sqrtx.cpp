class Solution {
public:
    int sqrt(int x0) {
        if (x0 == 0) return 0;
        double x = (double) x0;
        double xn = 0.5 * (x + x0 / x);
        while (xn - x > 0.1 || x - xn > 0.1){
            x = xn;
            xn = 0.5 * (x + x0 / x);
        }
        return (int) xn;
    }
};