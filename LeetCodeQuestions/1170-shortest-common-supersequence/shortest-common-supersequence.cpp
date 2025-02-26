#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);

class Solution {
public:

    string shortestCommonSupersequence(string s1, string s2) {
        NFS
        int n = s1.size(), m = s2.size();

        // Dp table
        vector<vector<int>> dp(n + 1, vector<int> (m + 1, 0));

        // Dp assumption: dp[i][j] -> Shortest common supersequence till i in s1 n till j in s2
        
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                // Base cases
                if (i == 0) {
                    dp[i][j] = j;
                    continue;
                }
                if (j == 0) {
                    dp[i][j] = i;
                    continue;
                }
                // dp expression to fill the table
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else {
                    dp[i][j] = 1 +  min(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        int i = n, j = m;
        string ans = "";
        while (i > 0 && j > 0) {
            if (s1[i - 1] == s2[j - 1]) {
                ans += s1[i - 1];
                i--, j--;
            }
            else if (dp[i - 1][j] < dp[i][j - 1]) {
                ans += s1[i-- - 1];
            }
            else {
                ans += s2[j-- - 1];
            }
        }

        while (i > 0) {
            ans += s1[i-- - 1];
        }

        while (j > 0) {
            ans += s2[j-- - 1];
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};