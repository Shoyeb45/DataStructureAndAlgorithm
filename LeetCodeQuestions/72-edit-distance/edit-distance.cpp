class Solution {
public:
    int minDistance(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // Base case initialization
        for (int i = 0; i <= n; i++) dp[i][0] = i;  // Deleting characters
        for (int j = 0; j <= m; j++) dp[0][j] = j;  // Inserting characters

        // Filling DP table
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s1[i - 1] == s2[j - 1]) {  // Correct indexing
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = 1 + min({
                        dp[i - 1][j - 1], // Replace
                        dp[i][j - 1],     // Insert
                        dp[i - 1][j]      // Delete
                    });
                }
            }
        }

        return dp[n][m];
    }
};
