class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        if (k >= m + n - 2)
            return m + n - 2;

        vector<vector<int>> vis(m, vector<int>(n, -1));

        queue<tuple<int,int,int>> q;
        q.push({0, 0, k});
        vis[0][0] = k;

        int steps = 0;

        vector<int> dr = {1, -1, 0, 0};
        vector<int> dc = {0, 0, 1, -1};

        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                auto [r, c, rem] = q.front();
                q.pop();

                if (r == m - 1 && c == n - 1)
                    return steps;

                for (int d = 0; d < 4; d++) {
                    int nr = r + dr[d];
                    int nc = c + dc[d];

                    if (nr < 0 || nc < 0 || nr >= m || nc >= n)
                        continue;

                    int newRem = rem - grid[nr][nc];

                    if (newRem < 0)
                        continue;

                    if (vis[nr][nc] >= newRem)
                        continue;

                    vis[nr][nc] = newRem;
                    q.push({nr, nc, newRem});
                }
            }

            steps++;
        }

        return -1;
    }
};