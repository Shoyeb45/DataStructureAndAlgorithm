class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, INT_MAX);
        for (int i = 0; i <= min(n, 3); i++) {
            dp[i] = i;
        }
        dp[0] = 0;
        for (int i = 4; i <= n; i++) {
            for (int j = 1; j * j <= i; j++) {

                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }
        for (int i = 0; i <= n; i++) {
            cout << dp[i] << " \n"[i == n];
        }
        return dp[n];
    }
};