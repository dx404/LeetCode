class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n <= 2) 
            return n;
        int wi = 2; // writeIndex
        for (int i = 2; i < n; i++){
            if (A[i] != A[wi - 2])
                A[wi++] = A[i];
        }
        return wi;
    }
    
};