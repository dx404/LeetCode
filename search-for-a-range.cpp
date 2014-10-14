class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        int low = -1, high = -1;
        if (n == 0)
            return {low, high};
        int a = 0, b = n - 1;
        while (a < b) {
            int mid = (a+b) / 2; // floor
            if (target <= A[mid]) {
                b = mid;    
            } else {
                a = mid + 1;
            }
        }
        low = (A[a] == target) ? a : -1;
        
        a = 0, b = n - 1;
        while (a < b) {
            int mid = (a+b+1) / 2; // ceiling
            if (target < A[mid]) {
                b = mid - 1;
            } else {
                a = mid;    
            }
        }
        high = (A[a] == target) ? a : -1;
        
        return {low, high};
    }
};