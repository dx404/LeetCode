class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n == 0) 
            return 0;
        // n >= 1
        int writeIndex = 1;
        for (int readIndex = 1; readIndex < n; readIndex++) {
            if (A[readIndex] != A[writeIndex - 1]) {
                A[writeIndex++] = A[readIndex];
            }
        }
        return writeIndex;
    }
};