class Solution {
public:
    int singleNumber(int A[], int n) {
        int high = 0;
        int low = 0;
        for (int i = 0; i < n; i++) {
            int newHigh = (high & ~low & ~A[i]) |  (~high & low & A[i]);
            int newLow = (~high & low & ~A[i]) |  (~high & ~low & A[i]) | (high & low & A[i]);
            high = newHigh;
            low = newLow;
        }
        return low;
    }
};