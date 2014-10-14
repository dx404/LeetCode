class Solution {
public:
    int numTrees(int n) {
        if (n <= 1){
            return 1;
        }
        int count = 0;
        for (int i = 0; i <= n-1; i++){
            count += numTrees(i) * numTrees(n-i-1);
        }
        return count;
    }
};