class Solution {
public:
    int climbStairs(int n) {
        int a = 1, b = 0;
        for (int i = 0; i <= n - 1; i++) {
            a = a + b;
            b = a - b;
        }
        return a;
    }
};