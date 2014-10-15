class Solution {
public: // Multiple partition quick sort
    void sortColors(int A[], int n) { 
        for (int i = -1, j = -1, k = 0; k < n; k++) {
            if (A[k] == 0) swap(A[++i], A[k]);
            j = max(j, i);
            if (A[k] == 1) swap(A[++j], A[k]);
        }
    }
};
