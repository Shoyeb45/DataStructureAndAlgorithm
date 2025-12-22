class Solution {
public:
    bool is_strs_sorted(int col_curr, int col_prev, vector<string> &a) {
        for (int i = 0; i < a.size(); i++) {
            if (a[i][col_prev] > a[i][col_curr]) 
                return false;
        }
        return true;
    }

    int minDeletionSize(vector<string>& strs) {
        int m = strs[0].size();
        // dp[curr][prev] = f(curr, prev + 1)

        vector dp(m + 1, vector<int> (m + 1, 0));

        for (int curr = m - 1; curr >= 0; curr--) {
            for (int prev = -1; prev < curr; prev++) {
                // delete the col 
                int ans = 1 + dp[curr + 1][prev + 1];
                if (prev == -1 || is_strs_sorted(curr, prev, strs)) {
                    ans = min(ans, dp[curr + 1][curr + 1]);
                } 
                dp[curr][prev + 1] = ans;
            }
        }

        return dp[0][0];
    }
};


