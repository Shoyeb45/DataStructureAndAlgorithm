class Solution {
public:
    vector<string> a;
    int dp[101][101];

    bool is_strs_sorted(int col_curr, int col_prev) {
        for (int i = 0; i < a.size(); i++) {
            if (a[i][col_prev] > a[i][col_curr]) 
                return false;
        }
        return true;
    }

    int f(int col_curr, int col_prev) {
        if (col_curr >= a[0].size()) return 0;

        if (col_prev != -1 && dp[col_curr][col_prev] != -1) 
            return dp[col_curr][col_prev];

        // delete the current column
        int ans = 1 + f(col_curr + 1, col_prev);

        // keep the column, only if it satisfy the condition
        if (col_prev == -1 || is_strs_sorted(col_curr, col_prev)) {
            ans = min(ans, f(col_curr + 1, col_curr));
        }
        return col_prev == -1 ? ans : dp[col_curr][col_prev] = ans;
    }
    int minDeletionSize(vector<string>& strs) {
        memset(dp, -1, sizeof(dp));
        this->a = strs;

        return f(0, -1);
    }
};


/*

babca
bbazb

*/