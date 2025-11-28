class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> adj(n);

        for (auto& ed: edges) {
            adj[ed[0]].push_back(ed[1]);
            adj[ed[1]].push_back(ed[0]);
        }   

        for (auto& x: values) x %= k;

        int ans = 0;
        std::function<int(int, int)> dfs = [&](int u, int parent) -> int {
            int overall_sum = values[u];

            for (auto &v: adj[u]) {
                if (v != parent) {
                    int temp = dfs(v, u);

                    if (temp != -1) {
                        overall_sum = (overall_sum + temp) % k;
                    }
                }
            }
            overall_sum %= k;
            if (overall_sum == 0) {
                ans++;
                overall_sum = -1;
            }
            return overall_sum;
        };
        dfs(0, -1);

        return ans;
    }
};