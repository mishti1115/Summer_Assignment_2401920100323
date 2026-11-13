class DSU {
public:
    vector<int> parent, size;

    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);

        for(int i = 0; i < n; i++)
            parent[i] = i;
    }

    int findUPar(int node) {
        if(parent[node] == node)
            return node;

        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v) {
        u = findUPar(u);
        v = findUPar(v);

        if(u == v) return;

        if(size[u] < size[v])
            swap(u, v);

        parent[v] = u;
        size[u] += size[v];
    }
};

class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {

        int n = s.size();

        DSU dsu(n);

        for(auto &p : pairs) {
            dsu.unionBySize(p[0], p[1]);
        }

        unordered_map<int, vector<int>> groups;

        for(int i = 0; i < n; i++) {
            groups[dsu.findUPar(i)].push_back(i);
        }

        string ans = s;

        for(auto &[parent, indices] : groups) {

            string chars;

            for(int idx : indices)
                chars.push_back(s[idx]);

            sort(indices.begin(), indices.end());
            sort(chars.begin(), chars.end());

            for(int i = 0; i < indices.size(); i++) {
                ans[indices[i]] = chars[i];
            }
        }

        return ans;
    }
};