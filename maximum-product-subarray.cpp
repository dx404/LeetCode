#define MAX3(x, y, z) max(max((x), (y)), (z))
#define MIN3(x, y, z) min(min((x), (y)), (z))
class Solution {
public:
    int maxProduct(int A[], int n) {
        pair<int, int> min_max_end_here = {A[0], A[0]};
        int maxSoFar = A[0];
        for (int i = 1; i < n; i++) {
            min_max_end_here = {
                MIN3(min_max_end_here.first * A[i], min_max_end_here.second * A[i], A[i]),
                MAX3(min_max_end_here.first * A[i], min_max_end_here.second * A[i], A[i]) 
            };
            maxSoFar = max(maxSoFar, min_max_end_here.second);
        }
        return maxSoFar;
    }
};