class Solution {
public:

    int minInsertions(string s) {
        int n = s.size();
        vector<vector<int>> dp(n + 1, vector<int> (n + 1, 0));

        // dp expression : dp[i][j] = dp[i + 1][j - 1]
        // dp[i][j] = 1 + min(dp[i + 1][j], dp[i][j - 1])

        for (int len = 2; len <= n; len++) {
            // Starting index
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;

                if (s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j - 1];
                }
                else {
                    dp[i][j] = 1 + min(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[0][n - 1];
    }
};