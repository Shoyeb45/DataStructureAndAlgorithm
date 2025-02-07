class Solution {
    int dp[201][201];

public:
    Solution() {
        memset(dp, -1, sizeof(dp));
    }
    int minPathSum(vector<vector<int>>& a, int row = 0, int col = 0) {
        if (row >= a.size() || col >= a[0].size()) {
            return INT_MAX;
        }
        if (dp[row][col] != -1) {
            return dp[row][col];
        }

        if (row == a.size() - 1 && col == a[0].size() - 1) {
            return a[row][col];
        }

        int right = minPathSum(a, row, col + 1);
        int down = minPathSum(a, row + 1, col);

        return dp[row][col] = min(right, down) + a[row][col];
    }
};