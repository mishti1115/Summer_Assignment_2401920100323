class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.size();
        const int INF = 1e9;

        vector<vector<int>> cost(n, vector<int>(n, INF));

        // Precompute cost[l][r]
        for (int l = 0; l < n; l++) {
            for (int r = l; r < n; r++) {
                int len = r - l + 1;

                if (len == 1) continue;

                int best = INF;

                for (int d = 1; d < len; d++) {
                    if (len % d) continue;

                    int cur = 0;
                    int block = len / d;

                    for (int rem = 0; rem < d; rem++) {
                        int L = 0;
                        int R = block - 1;

                        while (L < R) {
                            char c1 = s[l + rem + L * d];
                            char c2 = s[l + rem + R * d];

                            if (c1 != c2) cur++;

                            L++;
                            R--;
                        }
                    }

                    best = min(best, cur);
                }

                cost[l][r] = best;
            }
        }

        vector<vector<int>> dp(n + 1, vector<int>(k + 1, INF));
        dp[n][0] = 0;

        for (int i = n - 1; i >= 0; i--) {
            for (int part = 1; part <= k; part++) {

                for (int j = i + 1; j < n; j++) { // length >= 2
                    if (cost[i][j] == INF) continue;
                    if (dp[j + 1][part - 1] == INF) continue;

                    dp[i][part] = min(
                        dp[i][part],
                        cost[i][j] + dp[j + 1][part - 1]
                    );
                }
            }
        }

        return dp[0][k];
    }
};