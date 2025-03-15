class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        // make graph
        unordered_map<string, int> mp;
        vector< pair<pair<int, int>, double> > edges;
        int n = -1;

        for (int i = 0; i < equations.size(); i++) {
            string a = equations[i][0];
            string b = equations[i][1];

            if (mp.find(a) == mp.end()) {
                mp[a] = ++n;
            }

            if (mp.find(b) == mp.end()) {
                mp[b] = ++n;
            }

            edges.push_back({{mp[a], mp[b]}, values[i]});
        }
        vector<vector<pair<int, double>>> adj(n + 1);

        for (auto edge: edges) {
            adj[edge.first.first].push_back({edge.first.second, edge.second});
            adj[edge.first.second].push_back({edge.first.first, 1 / edge.second});
        }
        vector<vector<double>> ans(n + 1, vector<double> (n + 1, 1e9));
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                if (i == j) {
                    ans[i][j] = 1.0;
                }
            }
        }
        // cout << "adj " << '\n';

        // for (int i = 0; i <= n; i++) {
        //     cout << i << " -> ";
        //     for (auto x : adj[i]) {
        //         cout << "{" << x.first << ", " << x.second << "}, ";
        //     }
        //     cout << "\n";
        // }


        auto bfs = [&](int node) -> void {
            vector<bool> vis(n + 1, false);
            vis[node] = true;
            queue<int> q;
            q.push(node);
            while (!q.empty()) {
                int x = q.front();
                q.pop();

                for (auto y: adj[x]) {
                    if (!vis[y.first]) {
                        vis[y.first] = true;
                        q.push(y.first);
                        ans[node][y.first] = y.second * ans[node][x]; 
                    }
                }
            }
        };

        for (int i = 0; i <= n; i++) {
            bfs(i);
        }

        // for (auto x: ans) {
        //     for (auto y: x) {
        //         cout << y << " ";
        //     }
        //     cout << '\n';
        // }

        vector<double> queryAns;

        for (auto x: queries) {
            string a = x[0], b = x[1];

            if (mp.find(a) == mp.end() || mp.find(b) == mp.end() || ans[mp[a]][mp[b]] == 1e9) {
                queryAns.push_back(-1.0);
            }
            else {
                queryAns.push_back(ans[mp[a]][mp[b]]);
            }
        }
        return queryAns;
    }
};