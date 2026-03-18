class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        // build prefix sum matrix
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> pref(n + 1, vector<int> (m + 1));
        for (int i = 1; i <= n; i++) {
            pref[i][1] = pref[i - 1][1] + grid[i - 1][0];
        }
        for (int j = 1; j <= m; j++) {
            pref[1][j] = pref[1][j - 1] + grid[0][j - 1];
        }

        for (int i = 2; i <= n; i++) {
            for (int j = 2; j <= m; j++) {
                pref[i][j] =  (grid[i - 1][j - 1] + pref[i][j - 1] + pref[i - 1][j]) - pref[i - 1][j - 1];
            }
        }
        
        int ans = 0;
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                // cout << pref[i][j] << " ";
                if (pref[i][j] <= k) ans++;
            }
            // cout << endl;
        }
        return ans;
    }
};