#define vi vector<int>

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int end = (int) prices.size() - 1;
        vi mainProfitInfo = maxProfit(prices, 0, end);
        vi mainProfitDiff = minProfit(prices, mainProfitInfo[1], mainProfitInfo[2]);
        
        vi leftProfitInfo = maxProfit(prices, 0, mainProfitInfo[1] - 1);
        vi rightProfitInfo = maxProfit(prices, mainProfitInfo[2] + 1, end);
        return mainProfitInfo[0] + max(-mainProfitDiff[0], max(leftProfitInfo[0], rightProfitInfo[0]));
    }
    vi maxProfit(vector<int> &prices, int a, int b) {
        if (a >= b){
            return {0, a, b};
        }
        int iMinSoFar = a;
        int low = a, high = a;
        int minSoFar = numeric_limits<int>::max() >> 1;
        int maxDiff = 0;
        for (int i = a; i <= b; i++){
            if (prices[i] - minSoFar > maxDiff){
                maxDiff = prices[i] - minSoFar;
                high = i;
                low = iMinSoFar;
                
            }
            if (prices[i] < minSoFar){
                minSoFar = prices[i];
                iMinSoFar = i;
            }
            
        }
        return {maxDiff, low, high};
    }
    
    vi minProfit(vector<int> &prices, int a, int b) {
        if (a >= b){
            return {0, a, b};
        }
        int iMaxSoFar = a;
        int low = a, high = a;
        int maxSoFar = numeric_limits<int>::min() >> 1;
     
        int maxDiff = 0;
        for (int i = a; i <= b; i++){
            if (prices[i] - maxSoFar < maxDiff){
                maxDiff = prices[i] - maxSoFar;
                high = i;
                low = iMaxSoFar;
                
            }
            if (prices[i] > maxSoFar){
                maxSoFar = prices[i];
                iMaxSoFar = i;
            }
            
        }
        return {maxDiff, low, high};
    }
    
};