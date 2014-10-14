class Solution {
public:
    void sortColors(int A[], int n) {
        int colorCount[3] = {0,0,0};
        for (int i = 0; i < n; i++){
            colorCount[A[i]]++;
        }
        for(int i = 0; i < colorCount[0]; i++){
            A[i] = 0;
        }
        for(int i = colorCount[0]; i < colorCount[0] + colorCount[1]; i++){
            A[i] = 1;
        }
        for(int i = colorCount[0] + colorCount[1]; i < n; i++){
            A[i] = 2;
        }
    }
};