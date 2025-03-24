class Solution {
string s, p;
int dp[21][21];
public:
    int f(int i, int j) {
        if (i >= s.size() && j >= p.size()) {
            return 1;
        }
        else if (j >= p.size()) {
            return 0;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        
        bool match = (i < s.size() && (s[i] == p[j] || p[j] == '.'));

        if (j + 1 < p.size() && p[j + 1] == '*') {
            return dp[i][j] = f(i, j + 2) || (match? f(i + 1, j): false);
        } 
        else if (match) {
            return dp[i][j] = f(i + 1, j + 1);
        }
        return 0;
    }

    bool isMatch(string s, string p) {
        memset(dp, -1, sizeof(dp));
        this -> s = s, this -> p = p;
        return f(0, 0);
    }
};