class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        const int MOD = 1e9 + 7;
        int m = grid.size(), n = grid[0].size();

        vector<vector<vector<long long>>> dp(
            m, vector<vector<long long>>(n, vector<long long>(2, 0))
        );

        dp[0][0][0] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                long long r = dp[i][j][0];
                long long d = dp[i][j][1];

                if (grid[i][j] == 0) {
                    long long ways = (r + d) % MOD;

                    if (j + 1 < n)
                        dp[i][j + 1][0] =
                            (dp[i][j + 1][0] + ways) % MOD;

                    if (i + 1 < m)
                        dp[i + 1][j][1] =
                            (dp[i + 1][j][1] + ways) % MOD;
                }
                else {
                    if (i + 1 < m)
                        dp[i + 1][j][1] =
                            (dp[i + 1][j][1] + r) % MOD;

                    if (j + 1 < n)
                        dp[i][j + 1][0] =
                            (dp[i][j + 1][0] + d) % MOD;
                }
            }
        }

        return (dp[m - 1][n - 1][0] +
                dp[m - 1][n - 1][1]) % MOD;
    }
};