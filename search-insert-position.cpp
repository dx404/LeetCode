class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        int i;
        for(i = 0; i < n; i++) {
           if (target <= A[i]) break;
        }
        return i;
    }
};