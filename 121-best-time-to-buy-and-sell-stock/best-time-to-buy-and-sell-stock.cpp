class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int minPrices = prices[0];

        for (int i = 0; i < prices.size(); i++) {
            minPrices = min(minPrices, prices[i]);

            int Profit = prices[i] - minPrices;
            maxProfit = max(maxProfit, Profit);
        }

        return maxProfit;
    }
};