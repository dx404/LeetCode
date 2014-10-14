class Solution {
public:
    int candy(vector<int> &ratings) {
        int n = ratings.size();
        if (n <= 1) return n;
        vector<int> left(n), right(n);
        left[0] = 1;
        right[0] = 1;
        int x = 1;
        for (int i = 1; i < n; i++){
            left[i] = (ratings[i] > ratings[i-1]) ? ++x : (x = 1);
        }
        x = 1;
        for (int i = n - 2; i >= 0; i--) {
            right[i] = (ratings[i] > ratings[i+1]) ? ++x : (x = 1);
        }
        int total = 0;
        for (int i = 0; i < n; i++){
            total += max(left[i], right[i]);
        }
        return total;
    }
};