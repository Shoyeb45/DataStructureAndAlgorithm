class Solution {
public:
    int dp[1001][1001];

    int f(string &s1, string &s2, int idx1 = 0, int idx2 = 0) {
        if (idx1 >= s1.size() || idx2 >= s2.size()) {
            return 0;
        }

        if (dp[idx1][idx2] != -1) {
            return dp[idx1][idx2];
        }

        int ans = 0;
        if (s1[idx1] == s2[idx2]) {
            ans = 1 + f(s1, s2, idx1 + 1, idx2 + 1);
        }
        else {
            int incr1 = f(s1, s2, idx1 + 1, idx2);
            int incr2 = f(s1, s2, idx1, idx2 + 1);
            // int incrBoth = f(s1, s2, idx1 + 1, idx2 + 1);
            ans = max({incr1, incr2});
        }
        return dp[idx1][idx2] = ans;
    }

    int longestCommonSubsequence(string text1, string text2) {
        memset(dp, -1, sizeof(dp));
        return f(text1, text2);    
    }
};