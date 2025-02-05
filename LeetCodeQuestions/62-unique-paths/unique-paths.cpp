class Solution {
public:
    int uniquePaths(int n, int m) {
        vector<vector<int>> dp(n, vector<int> (m, 0));
        dp[0][0] = 1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int a = 0, b = 0;

                if (i == 0 && j == 0) {
                    continue;
                }

                if (i > 0) {
                    a = dp[i - 1][j];
                }
                if (j > 0) {
                    b = dp[i][j - 1];
                }
                dp[i][j] = a + b;
            }
        }

        return dp[n - 1][m - 1];
    }
};