class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        const int MAXF = 1500;
        int n = items.size();

        vector<int> freq(MAXF + 1, 0);
        for (auto &it : items) {
            freq[it[0]]++;
        }

        vector<int> multiples(MAXF + 1, 0);
        for (int f = 1; f <= MAXF; f++) {
            for (int m = f; m <= MAXF; m += f) {
                multiples[f] += freq[m];
            }
        }

        int cheapest = INT_MAX;
        for (auto &it : items) {
            cheapest = min(cheapest, it[1]);
        }

        vector<int> dp(budget + 1, -1);
        dp[0] = 0;

        for (auto &it : items) {
            int factor = it[0];
            int price = it[1];

            int value = multiples[factor]; // 1 bought copy + free copies

            for (int b = budget; b >= price; b--) {
                if (dp[b - price] != -1) {
                    dp[b] = max(dp[b], dp[b - price] + value);
                }
            }
        }

        int ans = budget / cheapest;

        for (int cost = 0; cost <= budget; cost++) {
            if (dp[cost] == -1) continue;

            ans = max(ans,
                      dp[cost] + (budget - cost) / cheapest);
        }

        return ans;
    }
};