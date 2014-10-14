class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int m = 0;
        for (int i = 0; i < n; i++){
            int u = A[i];
            if (u != elem) {
                A[m] = u;
                m++;
            }
        }
        return m ;
    }
};