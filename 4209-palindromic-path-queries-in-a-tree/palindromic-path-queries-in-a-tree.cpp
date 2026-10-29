
class Solution {
public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        vector<vector<int>> g(n);
        for (auto &e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }

        vector<int> par(n), dep(n), heavy(n, -1), head(n), pos(n), sz(n);
        int timer = 0;

        function<int(int,int)> dfs = [&](int u, int p) {
            par[u] = p;
            sz[u] = 1;
            int mx = 0;
            for (int v : g[u]) {
                if (v == p) continue;
                dep[v] = dep[u] + 1;
                int sub = dfs(v, u);
                sz[u] += sub;
                if (sub > mx) mx = sub, heavy[u] = v;
            }
            return sz[u];
        };

        function<void(int,int)> decompose = [&](int u, int h) {
            head[u] = h;
            pos[u] = timer++;
            if (heavy[u] != -1) decompose(heavy[u], h);
            for (int v : g[u])
                if (v != par[u] && v != heavy[u])
                    decompose(v, v);
        };

        dfs(0, -1);
        decompose(0, 0);

        vector<int> st(4 * n), a(n);
        for (int i = 0; i < n; i++)
            a[pos[i]] = 1 << (s[i] - 'a');

        function<void(int,int,int)> build = [&](int p, int l, int r) {
            if (l == r) {
                st[p] = a[l];
                return;
            }
            int m = (l + r) / 2;
            build(2*p, l, m);
            build(2*p+1, m+1, r);
            st[p] = st[2*p] ^ st[2*p+1];
        };

        function<void(int,int,int,int,int)> update =
        [&](int p, int l, int r, int i, int val) {
            if (l == r) {
                st[p] = val;
                return;
            }
            int m = (l + r) / 2;
            if (i <= m) update(2*p, l, m, i, val);
            else update(2*p+1, m+1, r, i, val);
            st[p] = st[2*p] ^ st[2*p+1];
        };

        function<int(int,int,int,int,int)> query =
        [&](int p, int l, int r, int L, int R) -> int {
            if (r < L || l > R) return 0;
            if (L <= l && r <= R) return st[p];
            int m = (l + r) / 2;
            return query(2*p, l, m, L, R) ^
                   query(2*p+1, m+1, r, L, R);
        };

        build(1, 0, n-1);

        auto pathXor = [&](int u, int v) {
            int res = 0;
            while (head[u] != head[v]) {
                if (dep[head[u]] < dep[head[v]]) swap(u, v);
                res ^= query(1, 0, n-1, pos[head[u]], pos[u]);
                u = par[head[u]];
            }
            if (dep[u] > dep[v]) swap(u, v);
            return res ^ query(1, 0, n-1, pos[u], pos[v]);
        };

        vector<bool> ans;
        for (auto &q : queries) {
            stringstream ss(q);
            string type;
            ss >> type;

            if (type == "update") {
                int u;
                char c;
                ss >> u >> c;
                s[u] = c;
                update(1, 0, n-1, pos[u], 1 << (c-'a'));
            } else {
                int u, v;
                ss >> u >> v;
                ans.push_back(__builtin_popcount(pathXor(u, v)) <= 1);
            }
        }
        return ans;
    }
};

