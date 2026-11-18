class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges,
                          vector<double>& succProb,
                          int start, int end) {

        vector<vector<pair<int,double>>> adj(n);

        for (int i = 0; i < edges.size(); i++) {

            int u = edges[i][0];
            int v = edges[i][1];
            double p = succProb[i];

            adj[u].push_back({v, p});
            adj[v].push_back({u, p});
        }

        vector<double> prob(n, 0.0);

        priority_queue<pair<double,int>> pq;

        prob[start] = 1.0;
        pq.push({1.0, start});

        while (!pq.empty()) {

            auto [currProb, node] = pq.top();
            pq.pop();

            if (node == end)
                return currProb;

            if (currProb < prob[node])
                continue;

            for (auto &[nbr, edgeProb] : adj[node]) {

                double newProb = currProb * edgeProb;

                if (newProb > prob[nbr]) {

                    prob[nbr] = newProb;

                    pq.push({newProb, nbr});
                }
            }
        }

        return 0.0;
    }
};