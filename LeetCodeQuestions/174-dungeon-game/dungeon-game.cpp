#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        NFS
        int n = dungeon.size(), m = dungeon[0].size();

        vector<vector<int>> dp(n, vector<int> (m));

        dp[n - 1][m - 1] = max(-dungeon[n - 1][m - 1] + 1, 1);

        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                cout << "index : " << i << " " << j << "\n";
                if (i == n - 1 && j == m - 1) {
                    continue;
                }

                int a = 1e9, b = a;

                if (i + 1 < n) {
                    a = dp[i + 1][j];
                }
                if (j + 1 < m) {
                    b = dp[i][j + 1];
                }
                cout << a << " " << b << "\n";
                dp[i][j] = max(min(a, b) - dungeon[i][j], 1);
            }
        }     

        return dp[0][0];
    }
};