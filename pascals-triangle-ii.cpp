class Solution {
public:
    vector<int> getRow(int k) {
        vector<int> pa(k+1, 1);
        for (int i = 2; i <= k; i++){
            for (int j = i - 1; j >= 1; j--){
                pa[j] += pa[j-1];
            }
        }
        return pa;
    }
};