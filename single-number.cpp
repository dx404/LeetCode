class Solution {
public:
    // A single pass of the given array using XOR 
    // Applies distinguish odd ones from the even ones 
    int singleNumber(int A[], int n) {
        int x = 0;
        for (int i = 0; i < n; i++) {
            x ^= A[i];
        }
        return x;
    }
};