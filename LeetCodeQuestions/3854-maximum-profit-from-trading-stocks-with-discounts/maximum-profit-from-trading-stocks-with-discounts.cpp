class Solution {
public:
    int B;  // total budget
    vector<vector<int>> tree;
    vector<int> present, future;

    // dp[u][parentBought][b]
    // max profit in subtree rooted at u
    // if parent is bought (0/1) with budget b
    vector<vector<vector<int>>> dp;

    static constexpr int NEG_INF = -1e9;

    // Knapsack merge:
    // combine two budget-profit arrays
    vector<int> merge(const vector<int>& A, const vector<int>& B2) {
        vector<int> C(B + 1, NEG_INF);
        for (int i = 0; i <= B; i++) {
            if (A[i] == NEG_INF) continue;
            for (int j = 0; i + j <= B; j++) {
                if (B2[j] == NEG_INF) continue;
                C[i + j] = max(C[i + j], A[i] + B2[j]);
            }
        }
        return C;
    }

    void dfs(int u) {
        // initialize dp arrays
        dp[u][0] = vector<int>(B + 1, 0);
        dp[u][1] = vector<int>(B + 1, 0);

        // process children
        for (int v : tree[u]) {
            dfs(v);
        }

        // parentBought = 0 or 1
        for (int parentBought = 0; parentBought <= 1; parentBought++) {
            int price = parentBought ? present[u] / 2 : present[u];
            int profit = future[u] - price;

            /* -------- Option 1: skip buying u -------- */
            vector<int> skip(B + 1, 0);
            for (int v : tree[u]) {
                skip = merge(skip, dp[v][0]);
            }

            /* -------- Option 2: buy u -------- */
            vector<int> take(B + 1, NEG_INF);
            if (price <= B) {
                vector<int> base(B + 1, 0);
                for (int v : tree[u]) {
                    // if u is bought, children see parentBought = 1
                    base = merge(base, dp[v][1]);
                }
                for (int b = price; b <= B; b++) {
                    take[b] = base[b - price] + profit;
                }
            }

            /* -------- Final DP for u -------- */
            for (int b = 0; b <= B; b++) {
                dp[u][parentBought][b] = max(skip[b], take[b]);
            }
        }
    }

    int maxProfit(
        int n,
        vector<int>& p,
        vector<int>& f,
        vector<vector<int>>& hierarchy,
        int budget
    ) {
        B = budget;
        present = p;
        future = f;

        tree.assign(n, {});
        for (auto& e : hierarchy) {
            tree[e[0] - 1].push_back(e[1] - 1);
        }

        dp.assign(n, vector<vector<int>>(2));
        dfs(0);

        int ans = 0;
        for (int b = 0; b <= B; b++) {
            ans = max(ans, dp[0][0][b]);
        }
        return ans;
    }
};
