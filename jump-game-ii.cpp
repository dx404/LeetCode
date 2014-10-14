class Solution {
public:
    int jump(int A[], int n) {
        if (n == 0)
            return 0;
        int counter = 0;
        pair<int, int> range = {0, 0};
        while (range.second < n - 1){
            range = nextStepRange(A, range);
            counter++;
        }
        return counter;
    }
    
    pair<int, int> nextStepRange(int A[], pair<int, int> &range){
        int farReach = range.first;
        for (int i = range.first; i <= range.second; i++){
            farReach = max(farReach, i + A[i]);
        }
        return {range.second + 1, farReach};
    }
    
};
