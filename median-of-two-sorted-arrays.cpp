#define A(i) (((i) < 0) ? numeric_limits<int>::min() : ((i) < m) ? A[i] : numeric_limits<int>::max())
#define B(i) (((i) < 0) ? numeric_limits<int>::min() : ((i) < n) ? B[i] : numeric_limits<int>::max())

class Solution{
public:
    int *A, *B;
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        this->A = A;
        this->B = B;
        if ((m+n) & 1){
            return find_kth((m+n)/2, m, n); // actual index
        }
        else{
            int low = find_kth((m+n)/2 - 1, m, n);
            int high = find_kth((m+n)/2, m, n);
            return (low + high) / 2.0;
        }
    }
    
    int find_kth(int k, int m, int n){
        if (k < 0 || k >= m + n)
            return 0;
        if (n == 0)
            return A[k];
        if (m == 0)
            return B[k];
        if (k == 0)
            return min(A[0], B[0]);
        if (k == m + n - 1)
            return max(A[m-1], B[n-1]);
        
        int base_a = min(m, k);
        int base_b = max(0, k - m);
        int d = min(m, k) - max(0, k - n) + 1;
        int start = 0, end = d - 1, mid = (start + end) / 2;
        while (start <= end) {
            int a = A(base_a - mid);
            int b = B(base_b + mid);
            if (a > b)
                start = mid + 1;
            else if (a < b)
                end = mid - 1;
            else
                return a;
            mid = (start + end) / 2;
        }
        int at = A(base_a - start);
        int bt = B(base_b + start - 1);
        return max(at, bt);
    }
};