class Solution {
public:
    // similar to interval merging
    bool canJump(int A[], int n) {
        if (n == 0)
            return false;
        int farReach = A[0];
        for (int i = 1; i <= n - 1; i++) {
            if (farReach < i) 
                return false;
                
            if (i + A[i] > farReach)
                farReach = i + A[i];
                
            if (farReach >= n - 1)
                return true;
        }
        return true;
    }
};