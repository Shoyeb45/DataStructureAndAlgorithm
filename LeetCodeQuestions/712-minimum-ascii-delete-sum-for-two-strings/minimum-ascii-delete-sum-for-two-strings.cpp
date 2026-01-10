class Solution {
public:
    int n, m;
    string s1, s2;

    int dp[1000][1000];

    int fn(int i, int j) {
        if (i >= n) {
            int to = 0;
            for (;j < m; j++) 
                to += s2[j];
            return to;
        } 
        if (j >= m) {
            int to = 0;
            for (; i < n; i++) 
                to += s1[i];
            return to;
        }

        if (dp[i][j] != -1) return dp[i][j];

        int ans1 = (int) s1[i] + fn(i + 1, j);
        int ans2 = (int) s2[j] + fn(i, j + 1);
        int skip = (s1[i] == s2[j] ? 0 : s1[i] + s2[j]) + fn(i + 1, j + 1);

        return dp[i][j] = min({ans1, ans2, skip});
    }
    int minimumDeleteSum(string s1, string s2) {
        this->s1 = s1, this->s2 = s2;
        n = s1.size(), m = s2.size();
        memset(dp, -1, sizeof(dp));
        return fn(0, 0);
    }

    // sea
    // eat 
    // 's' + f(ea eat)     ||   'e' + fn(sea, at) || 's' + 'e' + fn(ea, at)
    // 
    // 

};