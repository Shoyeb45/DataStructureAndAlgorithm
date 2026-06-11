const int MOD = (int) 1e9 + 7;
using ll = long long;
class Solution {
public:

// 101
// 2 + 
// 4 
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
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<int> tree[n + 1];

        for (auto &x: edges) {
            tree[x[0]].push_back(x[1]);
            tree[x[1]].push_back(x[0]);
        }
        
        queue<pair<int, int>> q;
        q.push(make_pair(1, 0));

        vector<bool> vis(n + 1, false);
        vis[1] = true;

        int mx_depth = 0;
        while (!q.empty()) {
            auto [node, depth] = q.front();
            q.pop();

            for (auto &x: tree[node]) {
                if (!vis[x]) {
                    q.push(make_pair(x, depth + 1));
                    vis[x] = true;
                }
            }
            mx_depth = max(depth, mx_depth);
        }

        cout << mx_depth << "\n";
        
        return fast_power(2, mx_depth - 1) % MOD;
    }
};