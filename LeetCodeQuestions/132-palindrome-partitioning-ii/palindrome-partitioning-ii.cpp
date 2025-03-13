class Solution {
public:
    vector<vector<int>> lps, dp;

    int f(int i, int j, string &s) {
        if (i > j) {
            return 0;
        } 

        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        if (lps[i][j] == j - i + 1) {
            return 0;
        }
        int ans = INT_MAX;
        for (int k = i; k < j; k++) {
            if (lps[i][k] == k - i + 1) {
                ans = min(ans, 1 + f(k + 1, j, s));
            }
        }

        return dp[i][j] = ans;
    }
    int minCut(string s) {
        int n = s.size();
        lps.assign(n, vector<int> (n, 0)), dp.assign(n, vector<int> (n, -1));

        // fill lps
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < n; j++) {
                if (i > j) {
                    lps[i][j] = 0;
                }
                else if (i == j) {
                    lps[i][j] = 1;
                }
                else {
                    if (s[i] == s[j]) {
                        lps[i][j] = 2 + lps[i + 1][j - 1];
                    }
                    else {
                        lps[i][j] = max(lps[i + 1][j], lps[i][j - 1]);
                    }
                }
            }
        }

        return f(0, n - 1, s);
    }
};