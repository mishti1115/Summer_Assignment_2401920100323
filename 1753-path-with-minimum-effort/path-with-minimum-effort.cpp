class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {

        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> effort(
            n,
            vector<int>(m, INT_MAX)
        );

        priority_queue<
            vector<int>,
            vector<vector<int>>,
            greater<vector<int>>
        > pq;

        effort[0][0] = 0;

        pq.push({0, 0, 0});

        vector<int> dr = {-1, 0, 1, 0};
        vector<int> dc = {0, 1, 0, -1};

        while (!pq.empty()) {

            auto curr = pq.top();
            pq.pop();

            int diff = curr[0];
            int r = curr[1];
            int c = curr[2];

            if (r == n - 1 && c == m - 1)
                return diff;

            for (int k = 0; k < 4; k++) {

                int nr = r + dr[k];
                int nc = c + dc[k];

                if (nr >= 0 && nr < n &&
                    nc >= 0 && nc < m) {

                    int edgeCost =
                        abs(heights[r][c] -
                            heights[nr][nc]);

                    int newEffort =
                        max(diff, edgeCost);

                    if (newEffort < effort[nr][nc]) {

                        effort[nr][nc] = newEffort;

                        pq.push({
                            newEffort,
                            nr,
                            nc
                        });
                    }
                }
            }
        }

        return 0;
    }
};
