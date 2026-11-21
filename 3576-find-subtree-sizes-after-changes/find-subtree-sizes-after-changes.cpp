class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {

        int n = parent.size();

        vector<vector<int>> tree(n);

        for (int i = 1; i < n; i++) {
            tree[parent[i]].push_back(i);
        }

        vector<int> newParent = parent;

        vector<vector<int>> pos(26);

        function<void(int)> dfs = [&](int node) {

            int c = s[node] - 'a';

            if (!pos[c].empty()) {
                newParent[node] = pos[c].back();
            }

            pos[c].push_back(node);

            for (int child : tree[node]) {
                dfs(child);
            }

            pos[c].pop_back();
        };

        dfs(0);

        vector<vector<int>> finalTree(n);

        for (int i = 1; i < n; i++) {
            finalTree[newParent[i]].push_back(i);
        }

        vector<int> ans(n);

        function<int(int)> dfsSize = [&](int node) {

            int sz = 1;

            for (int child : finalTree[node]) {
                sz += dfsSize(child);
            }

            return ans[node] = sz;
        };

        dfsSize(0);

        return ans;
    }
};