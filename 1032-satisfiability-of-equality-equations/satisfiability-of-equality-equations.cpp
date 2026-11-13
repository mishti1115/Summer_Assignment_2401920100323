class DSU {
public:
    vector<int> parent, size;

    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);

        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int findUPar(int node) {
        if (parent[node] == node)
            return node;

        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v) {
        u = findUPar(u);
        v = findUPar(v);

        if (u == v) return;

        if (size[u] < size[v])
            swap(u, v);

        parent[v] = u;
        size[u] += size[v];
    }
};

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {

        DSU dsu(26);

        // Process all equalities
        for (string& eq : equations) {
            if (eq[1] == '=') {
                int u = eq[0] - 'a';
                int v = eq[3] - 'a';

                dsu.unionBySize(u, v);
            }
        }

        // Check all inequalities
        for (string& eq : equations) {
            if (eq[1] == '!') {
                int u = eq[0] - 'a';
                int v = eq[3] - 'a';

                if (dsu.findUPar(u) == dsu.findUPar(v))
                    return false;
            }
        }

        return true;
    }
};