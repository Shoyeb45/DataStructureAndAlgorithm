class Solution {
public:
    int superEggDrop(int k, int n) {
        vector<vector<int>> dp(n + 1, vector<int> (k + 1, INT_MAX));

        for (int i = 0; i <= k; i++) {
            dp[0][i] = 0;
        }
        for (int i = 0; i <= n; i++) {
            dp[i][1] = i;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 2; j <= k; j++) {

                int low = 1, high = i;
                int ans = INT_MAX;
                while (low <= high) {
                    int mid = (low + high) / 2;
                    int egg_break = dp[mid - 1][j - 1];
                    int egg_nb = dp[i - mid][j];
                    int worst = max(egg_break, egg_nb) + 1;

                    if (egg_break > egg_nb) {
                        high = mid - 1;
                    } else {
                        low = mid + 1;
                    }
                    ans = min(ans, worst);
                }
                dp[i][j] = ans;
            }
        }
        return dp[n][k];
    }
};