class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int *T = new int[m+n]; 
        int i = 0, j = 0, t = 0;
        while (i < m && j < n){
            T[t++] = (A[i] < B[j]) ? A[i++]: B[j++];
        }
        while (i != m){
            T[t++] = A[i++];
        }
        while (j != n){
            T[t++] = B[j++];
        }
        for(int i = 0; i < m + n; i++){
            A[i] = T[i];
        }
        delete [] T;
    }
};