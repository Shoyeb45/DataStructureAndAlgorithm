const int MOD = (int) 1e9 + 7;
using ll = long long;


class Solution {
public:
    vector<vector<int>> parent;
    vector<int> depth;
    int n;

    void init(vector<vector<int>> &edges) {
        parent.resize(n + 1, vector<int> (32, -1));
        depth.resize(n + 1, 0);
        
        vector<vector<int>> adj(n + 1);

        for (auto &x: edges) {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }

        dfs(1, -1, 0, adj);

        // fill parent tables
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j < 31; j++) {
                int x = parent[i][j - 1];
                if (x != -1) {
                    parent[i][j] = parent[x][j - 1];
                }
            }
        }
    }


    void dfs(int u, int p, int d, vector<vector<int>> &adj) {
        depth[u] = d;
        parent[u][0] = p;

        for (auto &v: adj[u]) {
            if (v != p) {
                dfs(v, u, d + 1, adj);
            }
        }
    }

    int fast_power(int b, int power) {
        long long ans = 1;
        long long base = b;

        while (power > 0) {
            if ((power & 1)) {
                ans = (ll) base * ans % MOD;
            }
            base = (ll) base * base % MOD;
            power >>= 1;
        }

        return (int) ans % MOD;
    }

    int get_lca(int u, int v) {
        if (depth[u] < depth[v]) swap(u, v);

        int diff = depth[u] - depth[v];

        for (int i = 30; i >= 0; i--) {
           // extract bit
            int bit = ((1 << i) & diff);
            if (bit) {
                if (parent[u][i] != -1)
                    u = parent[u][i];
            }
        }

        if (u == v) {
            return v;
        }

        for (int i = 30; i >= 0; i--) {
            if (parent[u][i] != parent[v][i]) {
                u = parent[u][i];
                v = parent[v][i];
            }
        }

        return parent[u][0];
    }

    int get_edge_len(int u, int v) {
        int lca = get_lca(u, v);
        return depth[u] + depth[v] - 2 * depth[lca];
    }

    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        this->n = edges.size() + 1;
        init(edges);

        vector<int> ans;

        for (auto &x: queries) {
            int edge_length = get_edge_len(x[0], x[1]);
            if (edge_length == 0) {
                ans.push_back(0);
            } else {
                ans.push_back(fast_power(2, edge_length - 1));
            }
        }

        return ans;
    }
};