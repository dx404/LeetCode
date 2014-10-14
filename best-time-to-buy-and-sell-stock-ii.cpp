class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        if (n == 0 || n == 1)
            return 0;
        int maxProfit = 0;
        for (int i = 1; i < n; i++) {
            maxProfit += max(0, prices[i] - prices[i-1]);
        }
        return maxProfit;
    }
};