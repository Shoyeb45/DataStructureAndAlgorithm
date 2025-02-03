class Solution {
public:
    vector<int> dp;

    Solution() {
        dp.resize((int)(1e4 + 1), -1);
    }

    int numSquares(int n, int oper = 0) {
        if (n == 0) {
            return oper;
        }

        if (dp[n] != -1) {
            return dp[n] + oper; 
        }

        int ans = INT_MAX;
        
        for (int i = 1; i * i <= n; i++) {
            ans = min(ans, numSquares(n - i * i, oper + 1));
        }

        dp[n] = ans - oper;
        return ans;
    }
};
