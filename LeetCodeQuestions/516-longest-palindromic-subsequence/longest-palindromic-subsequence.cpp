class Solution {
public:

    // int dp[1001][1001];
    // int f(string &s, int i, int j) {
    //     if (j == i) {
    //         return dp[i][j] = 1;
    //     }

        
    //     if (j < i) {
    //         return 0;
    //     }

    //     if (dp[i][j] != -1) {
    //         return dp[i][j];
    //     }
    //     if (s[i] == s[j]) { 
    //         return dp[i][j] = 2 + f(s, i + 1, j - 1);;
    //     }
        
    //     return dp[i][j] = max(f(s, i + 1, j), f(s, i, j - 1));
    // }
// Iterative dp
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int> (n));
        int mx_len = 0;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < n; j++) {
                if (i > j) {
                    dp[i][j] = 0;
                }
                else if (i == j) {
                    dp[i][j] = 1;
                }
                else {
                    if (s[i] == s[j]) {
                        dp[i][j] = 2 + dp[i + 1][j - 1];
                    }
                    else {
                        dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                    }
                }

                if (dp[i][j] == j - i + 1) {
                    mx_len = max(dp[i][j], mx_len);
                }
            }
        }
 
        return dp[0][n - 1];
    }
};