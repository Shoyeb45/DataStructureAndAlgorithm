class Solution {
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections,
                               vector<vector<int>>& queries) {
        vector<vector<int>> adj(c + 1);
        for (auto x : connections) {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        vector<int> ans(c + 1);
        for (int i = 1; i <= c; i++) {
            ans[i] = i;
        }
        vector<int> a;
        vector<int> comp(c + 1);
        vector<int> vis(c + 1, false);

        function<void(int, int)> dfs = [&](int u, int compId) -> void {
            vis[u] = true;
            comp[u] = compId;
            for (auto v : adj[u]) {
                if (!vis[v]) {
                    dfs(v, compId);
                }
            }
        };
        int compoId = 0;
        for (int i = 1; i <= c; i++) {
            if (!vis[i]) {
                dfs(i, compoId++);
            }
        }
        vector<set<int>> compo_vertices(compoId + 1);
        for (int i = 1; i <= c; i++) {
            compo_vertices[comp[i]].insert(i);
        }

        for (auto query : queries) {
            int u = query[1];
            if (query[0] == 2) {
                ans[u] = -1;
                compo_vertices[comp[u]].erase(u);
            } else {
                if (ans[u] == u) {
                    a.push_back(u);
                } else {
                    int com = comp[u];
                    if (compo_vertices[com].empty()) {
                        a.push_back(-1);
                    } else {
                        a.push_back(*compo_vertices[com].begin());
                    }
                }
            }
        }
        return a;
    }
};