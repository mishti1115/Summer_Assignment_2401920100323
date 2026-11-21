class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const long long INF = 1e18;
        const int MOD = 1e9 + 7;

        vector<vector<pair<int, int>>> adj(n);

        for (auto &r : roads) {
            int u = r[0];
            int v = r[1];
            int t = r[2];

            adj[u].push_back({v, t});
            adj[v].push_back({u, t});
        }

        vector<long long> dist(n, INF);
        vector<long long> ways(n, 0);

        priority_queue<
            pair<long long, int>,
            vector<pair<long long, int>>,
            greater<pair<long long, int>>
        > pq;

        dist[0] = 0;
        ways[0] = 1;

        pq.push({0, 0});

        while (!pq.empty()) {
            auto [d, node] = pq.top();
            pq.pop();

            if (d > dist[node]) continue;

            for (auto &[nbr, wt] : adj[node]) {

                long long newDist = d + wt;

                if (newDist < dist[nbr]) {

                    dist[nbr] = newDist;
                    ways[nbr] = ways[node];

                    pq.push({newDist, nbr});
                }
                else if (newDist == dist[nbr]) {

                    ways[nbr] =
                        (ways[nbr] + ways[node]) % MOD;
                }
            }
        }

        return ways[n - 1];
    }
};