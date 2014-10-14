class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        int preMin = numeric_limits<int>::max();
        int maxDiff = 0;
        for (int i = 0; i < n; i++) {
            maxDiff = max(maxDiff, prices[i] - preMin);
            preMin = min(preMin, prices[i]);
        }
        return maxDiff;
    }
};