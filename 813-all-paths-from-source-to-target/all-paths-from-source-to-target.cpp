class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;

    void dfs(vector<vector<int>>& graph, int node, int target) {
        path.push_back(node);

        if(node == target) {
            ans.push_back(path);
            path.pop_back();
            return;
        }

        for(int next : graph[node]) {
            dfs(graph, next, target);
        }

        path.pop_back();
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();

        dfs(graph, 0, n-1);

        return ans;
    }
};