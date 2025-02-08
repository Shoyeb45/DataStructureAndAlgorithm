#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);

class Solution {
public:
    vector<vector<int>> dp;

    int f(vector<vector<int>> &grid, vector<vector<int>> &moveCost, int col, int row = 0) {
        if (row == grid.size() - 1) {
            return grid[row][col];
        }

        if (dp[row][col] != -1) {
            return dp[row][col];
        }

        int ans = INT_MAX;
        for (int i = 0; i < grid[0].size(); i++) {
            ans = min(ans, f(grid, moveCost, i, row + 1) + grid[row][col] + moveCost[grid[row][col]][i]) ;
        }

        return dp[row][col] = ans;
    }

    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        NFS
        int ans = INT_MAX;
        dp.resize(grid.size() , vector<int>(grid[0].size(), -1));

        for (int i = 0; i < grid[0].size(); i++) {
            int d = f(grid, moveCost, i);
            cout << d << "\n";
            ans = min(ans, d);
        }
        return ans;
    }
};