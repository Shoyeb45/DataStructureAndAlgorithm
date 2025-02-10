class Solution {
public:
    int dp[201][201];
    Solution() {
        memset(dp, -1, sizeof(dp));
    }

    int calculateMinimumHP(vector<vector<int>>& dungeon, int row = 0, int col = 0) {
        if (row >= dungeon.size() || col >= dungeon[0].size()) {
            return INT_MAX;
        }
        if (row == dungeon.size() - 1 && col == dungeon[0].size() - 1) {
            return max(-dungeon[row][col] + 1, 1);
        }

        if (dp[row][col] != -1) {
            return dp[row][col];
        }

        int a = calculateMinimumHP(dungeon, row + 1, col);
        int b = calculateMinimumHP(dungeon, row, col + 1);
        cout << a << " " << b << "\n";

        return dp[row][col] = max(min(a, b) - dungeon[row][col], 1);
    }
};