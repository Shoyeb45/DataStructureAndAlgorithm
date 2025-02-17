// Iterative Dp

#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);

class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
        NFS
        // Define dp table
        int n = s1.size(), m = s2.size();
        vector<vector<int>> dp(n, vector<int> (m, 0));

        // expression : if equal : dp[i][j] = 1 + dp[i - 1][j - 1], else : dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])

        // Building dp table
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int a = 0, b = 0, c = 0;

                if (i - 1 >= 0) {
                    a = dp[i - 1][j]; 
                }
                if (j - 1 >= 0) {
                    b = dp[i][j - 1];
                }
                if (i - 1 >= 0 && j - 1 >= 0) {
                    c = dp[i - 1][j - 1];
                }

                if (s1[i] == s2[j]) {
                    dp[i][j] = 1 + c;
                }
                else {
                    dp[i][j] = max(a, b);
                }
            }
        } 

        return dp[n - 1][m - 1];
    }
};