class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int sx = 0, sy = 0;
        int totalKeys = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                char ch = grid[i][j];

                if (ch == '@') {
                    sx = i;
                    sy = j;
                }

                if (ch >= 'a' && ch <= 'f')
                    totalKeys++;
            }
        }

        int targetMask = (1 << totalKeys) - 1;

        queue<tuple<int,int,int,int>> q;
        q.push({sx, sy, 0, 0});

        vector<vector<vector<bool>>> vis(
            m,
            vector<vector<bool>>(n,
            vector<bool>(1 << 6, false))
        );

        vis[sx][sy][0] = true;

        int dr[] = {1,-1,0,0};
        int dc[] = {0,0,1,-1};

        while (!q.empty()) {
            auto [r,c,mask,steps] = q.front();
            q.pop();

            if (mask == targetMask)
                return steps;

            for (int d = 0; d < 4; d++) {
                int nr = r + dr[d];
                int nc = c + dc[d];

                if (nr < 0 || nc < 0 || nr >= m || nc >= n)
                    continue;

                char cell = grid[nr][nc];

                if (cell == '#')
                    continue;

                int newMask = mask;

                if (cell >= 'a' && cell <= 'f') {
                    newMask |= (1 << (cell - 'a'));
                }

                if (cell >= 'A' && cell <= 'F') {
                    if (!(mask & (1 << (cell - 'A'))))
                        continue;
                }

                if (vis[nr][nc][newMask])
                    continue;

                vis[nr][nc][newMask] = true;
                q.push({nr, nc, newMask, steps + 1});
            }
        }

        return -1;
    }
};