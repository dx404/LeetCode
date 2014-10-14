class Solution {
public:
    int maxSubArray(int A[], int n) {
        if (n == 0)
            return 0;
        int maxEndingHere = A[0];
        int maxSoFar = A[0];
        for (int i = 1; i < n; i++) {
            maxEndingHere = max(maxEndingHere + A[i], A[i]);
            maxSoFar = max(maxSoFar, maxEndingHere);
        }
        return maxSoFar;
    }
};