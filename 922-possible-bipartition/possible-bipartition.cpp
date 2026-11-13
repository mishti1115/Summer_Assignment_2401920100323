class Solution {
public:
    bool dfs(int node, int clr, vector<vector<int>>& adj, vector<int>& color) {
        color[node] = clr;

        for (int nei : adj[node]) {
            if (color[nei] == -1) {
                if (!dfs(nei, 1 - clr, adj, color))
                    return false;
            }
            else if (color[nei] == clr) {
                return false;
            }
        }

        return true;
    }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n + 1);

        for (auto& d : dislikes) {
            adj[d[0]].push_back(d[1]);
            adj[d[1]].push_back(d[0]);
        }

        vector<int> color(n + 1, -1);

        for (int i = 1; i <= n; i++) {
            if (color[i] == -1) {
                if (!dfs(i, 0, adj, color))
                    return false;
            }
        }

        return true;
    }
};