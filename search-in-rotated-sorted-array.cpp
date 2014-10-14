class Solution {
public:
    int search(int A[], int n, int target) {
        int index = -1;
        for (int i = 0; i < n; i++){
            if (A[i] == target){
                return i;
            } 
        }
        return index;
    }
};