// recursive solution
class Solution {
public:
    int dp[501][501];
    int f(string &s1, string &s2, int idx1, int idx2) {
        // base case
        if (idx1 < 0 && idx2 < 0) {
            return 0;  // convert "" -> ""
        }
        else if (idx2 < 0) {
            return idx1 + 1; // convert s1s2...s_idx1 -> ""
        }
        else if (idx1 < 0) {
            return idx2 + 1; 
        }
        if (dp[idx1][idx2] != -1) {
            return dp[idx1][idx2];
        }

        if (s1[idx1] == s2[idx2]) {
            return dp[idx1][idx2] = f(s1, s2, idx1 - 1, idx2 - 1);
        }

        return dp[idx1][idx2] = min({
            f(s1, s2, idx1, idx2 - 1),     // insert
            f(s1, s2, idx1 - 1, idx2 - 1), // replace
            f(s1, s2, idx1 - 1, idx2)      // delete
        }) + 1;
    }
    int minDistance(string word1, string word2) {
        memset(dp, -1, sizeof(dp));
        return f(word1, word2, word1.size() - 1, word2.size() - 1);
    }
};