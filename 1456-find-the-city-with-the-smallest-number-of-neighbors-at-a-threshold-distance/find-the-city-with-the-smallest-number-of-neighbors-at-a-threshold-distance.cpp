class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        const int INF = 1e9;

        vector<vector<int>> dist(n, vector<int>(n, INF));

        for (int i = 0; i < n; i++) {
            dist[i][i] = 0;
        }

        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];

            dist[u][v] = w;
            dist[v][u] = w;
        }

        for (int via = 0; via < n; via++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    dist[i][j] = min(dist[i][j],
                                     dist[i][via] + dist[via][j]);
                }
            }
        }

        int answer = -1;
        int minReachable = INT_MAX;

        for (int city = 0; city < n; city++) {
            int cnt = 0;

            for (int next = 0; next < n; next++) {
                if (city != next &&
                    dist[city][next] <= distanceThreshold) {
                    cnt++;
                }
            }

            if (cnt <= minReachable) {
                minReachable = cnt;
                answer = city;   // larger index wins on tie
            }
        }

        return answer;
    }
};