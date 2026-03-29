class Solution {
public:

    // on ith day, what we can day
    // buying: 
    //      when we don't have any stock or we are not in cooldown
    // sell:
    //      when we have stock
    int f(int i, int j, vector<vector<int>> &dp, vector<int>& p) {
        if (i >= p.size()) {
            return 0;
        }   

        if (dp[i][j + 1] != -1) return dp[i][j + 1];

        int ans = f(i + 1, j, dp, p);
        // we can buy
        if (j == -1) {
            ans = max(ans, f(i + 1, i, dp, p));
        } else {
            // selling
            int gain = p[i] - p[j];
            ans = max(ans, gain + f(i + 2, -1, dp, p));
        }

        return dp[i][j + 1] = ans;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector dp(n, vector<int> (n + 1, -1));

        return f(0, -1, dp, prices);
    }
};