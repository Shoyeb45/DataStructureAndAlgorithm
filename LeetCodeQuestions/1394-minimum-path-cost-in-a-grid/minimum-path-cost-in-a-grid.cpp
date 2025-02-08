#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);

class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        NFS
        int n = grid.size(), m = grid[0].size();

        vector<vector<int>> dp(n, vector<int> (m, 0));

        dp[0] = grid[0];

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                dp[i][j] = grid[i][j]; 
                int temp = INT_MAX;
                for (int k = 0; k < m; k++) {
                    temp = min(temp, dp[i - 1][k] + moveCost[grid[i - 1][k]][j]);
                }
                dp[i][j] += temp; 
            }
        }

        return *min_element(dp.back().begin(), dp.back().end());
    }
};