class Solution {
public:
    vector<int> shortestAlternatingPaths(
        int n,
        vector<vector<int>>& redEdges,
        vector<vector<int>>& blueEdges) {

        vector<vector<pair<int,int>>> adj(n);

        // 0 = red, 1 = blue
        for (auto &e : redEdges) {
            adj[e[0]].push_back({e[1], 0});
        }

        for (auto &e : blueEdges) {
            adj[e[0]].push_back({e[1], 1});
        }

        vector<int> answer(n, -1);
        vector<vector<bool>> vis(n, vector<bool>(2, false));

        queue<pair<int,int>> q;

        q.push({0, 0});
        q.push({0, 1});

        vis[0][0] = true;
        vis[0][1] = true;

        int steps = 0;

        while (!q.empty()) {

            int sz = q.size();

            while (sz--) {

                auto [node, lastColor] = q.front();
                q.pop();

                if (answer[node] == -1)
                    answer[node] = steps;

                for (auto &[nbr, edgeColor] : adj[node]) {

                    if (edgeColor == lastColor)
                        continue;

                    if (vis[nbr][edgeColor])
                        continue;

                    vis[nbr][edgeColor] = true;
                    q.push({nbr, edgeColor});
                }
            }

            steps++;
        }

        return answer;
    }
};