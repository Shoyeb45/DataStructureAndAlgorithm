using ll = long long;

class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        vector<ll> row(n), col(m);

        for (int i = 0; i < n; i++) {
            row[i] = accumulate(grid[i].begin(), grid[i].end(), 0LL);
        }

        for (int j = 0; j < m; j++) {
            col[j] = 0;
            for (int i = 0; i < n; i++) col[j] += grid[i][j];
        }

        auto prefix_find = [&](vector<ll> &a) -> void {
            for (int i = 1; i < a.size(); i++) a[i] += a[i - 1];
        };
     
        prefix_find(row);
        prefix_find(col);
 
        auto check_ans = [&](vector<ll> &a) -> bool {
            int n = a.size();
            for (int i = 0; i < n - 1; i++) {
                if (2 * a[i] == a[n - 1]) return true;
            }
            return false;
        };

        return check_ans(row) || check_ans(col);
    }
};