class Solution {
public:
    int dp[1001][1001];
    int f(string &s, int i, int j) {
        if (j == i) {
            return 1;
        }

        
        if (j < i) {
            return 0;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        if (s[i] == s[j]) { 
            return 2 + f(s, i + 1, j - 1);;
        }
        
        return dp[i][j] = max(f(s, i + 1, j), f(s, i, j - 1));
    }
    
    int longestPalindromeSubseq(string s) {
        memset(dp, -1, sizeof(dp));
        
        return f(s, 0, s.size() - 1);
    }
};