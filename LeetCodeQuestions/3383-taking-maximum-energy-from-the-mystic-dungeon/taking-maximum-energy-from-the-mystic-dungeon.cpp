class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        // 5 2 -10 -5 1
        // So we need to take 5 -5 , 2 1
        // dp[i] -> maximum from i
        int n = energy.size();
        vector<int> dp(n, 0);
        for (int i = n - k; i < n; i++) {
            dp[i] = energy[i];
        }

        // for (int i = 0;  i < n; i++) {
        //     cout << dp[i] << " ";
        // }
        // cout << "\n";
        for (int i = n - k - 1; i >= 0; i--) {
            dp[i] = energy[i] + dp[i + k];
        }
        // for (int i = 0;  i < n; i++) {
        //     cout << dp[i] << " ";
        // }
        // cout << "\n";

        return *max_element(dp.begin(), dp.end());
    }
};