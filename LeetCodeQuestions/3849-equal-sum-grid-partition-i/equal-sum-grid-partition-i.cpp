using ll = long long;

class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        vector<vector<ll>> pref(n + 1, vector<ll> (m + 1, 0));

        for (int i = 1; i <= n; i++) {
            pref[i][1] = pref[i - 1][1] + grid[i - 1][0];
        }

        for (int j = 1; j <= m; j++) {
            pref[1][j] = pref[1][j - 1] + grid[0][j - 1];
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                pref[i][j] = pref[i - 1][j] + pref[i][j - 1] + grid[i - 1][j - 1] - pref[i - 1][j - 1];
            }
        }

        for (int i = 1; i <= n; i++) {
            if (pref[i][m] == pref[n][m] - pref[i][m]) return true;
        }
        for (int j = 1; j <= m; j++) {
            if (pref[n][j] == pref[n][m] - pref[n][j]) return true;
        }
        return false;
    }
};