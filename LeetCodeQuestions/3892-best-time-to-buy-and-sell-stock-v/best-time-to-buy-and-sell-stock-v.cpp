using ll = long long;

class Solution {
public:
    vector<int> a;
    int k;

    ll dp[1005][505][3];

    ll f(int i, int t, int state) {
        if (i == a.size()) return state ? LLONG_MIN / 2 : 0;

        if (dp[i][t][state] != -1) 
            return dp[i][t][state];
        // don't buy or sell
        ll ans = f(i + 1, t, state);

        if (state == 0) {
            ans = max(ans, f(i + 1, t, 1) - a[i]);
            ans = max(ans, f(i + 1, t, 2) + a[i]);
        } 
        else if (state == 1 && t < k) {
            ans = max(ans, f(i + 1, t + 1, 0) + a[i]);
        }
        else if (state == 2 && t < k) {
            ans = max(ans, f(i + 1, t + 1, 0) - a[i]);
        }

        return dp[i][t][state] = ans;
    }
    long long maximumProfit(vector<int>& prices, int k) {
        a = prices;
        this->k = k;
        memset(dp, -1, sizeof dp);

        return f(0, 0, 0);
    }
};