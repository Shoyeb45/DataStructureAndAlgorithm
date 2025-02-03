class Solution {
public:
    vector<int> dp;
    Solution() {
        dp.resize((int)(1e4 + 1), -1);
    }
    int numSquares(int n) {
        if (n <= 3) {
            return n;
        }

        if (dp[n] != -1) {
            return dp[n];
        }

        int ans = INT_MAX;
        for (int i = 1; i * i <= n; i++) {
            ans = min(ans, numSquares(n - i * i) + 1);
        }

        return dp[n] = ans;
    }
};