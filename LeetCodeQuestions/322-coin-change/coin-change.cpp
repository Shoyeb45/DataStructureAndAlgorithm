class Solution {
public:
    vector<vector<int>> dp;

    int f(vector<int> &c, int amt, int idx) {
        if (amt == 0) {
            return 0;
        }
        if (idx < 0 || amt < 0) {
            return INT_MAX / 2;
        }

        if (dp[idx][amt] != -1) {
            return dp[idx][amt];
        }

        int notTake = f(c, amt, idx - 1);
        int take = INT_MAX;

        if (amt >= c[idx]) {
            take = 1 + f(c, amt - c[idx], idx);
        }
        // cout << take << " " << notTake << "\n";

        return dp[idx][amt] = min(take, notTake);
    }

    int coinChange(vector<int>& coins, int amount) {
        dp.resize(coins.size(), vector<int> (amount + 1, -1));

        int ans = f(coins, amount, coins.size() - 1);
        return (ans >= INT_MAX / 2? -1: ans);
    }
};