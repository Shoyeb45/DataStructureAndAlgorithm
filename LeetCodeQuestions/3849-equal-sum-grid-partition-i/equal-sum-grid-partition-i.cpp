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

        auto prefix_find = [&](vector<ll> &a) -> vector<ll> {
            vector<ll> pref(a.begin(), a.end());
            for (int i = 1; i < a.size(); i++) pref[i] += pref[i - 1];
            return pref;
        };
        auto suffix_find = [&](vector<ll> &a) -> vector<ll> {
            vector<ll> suff(a.begin(), a.end());
            for (int i = (int) a.size() - 2; i >= 0; i--) suff[i] += suff[i + 1];
            return suff;
        };

        auto pref_row = prefix_find(row);
        auto pref_col = prefix_find(col);
        
        auto suff_row = suffix_find(row);
        auto suff_col = suffix_find(col);

        // 3   2  1  4
        // 3   5  6  10
        // 10  7  5  4
        auto check_ans = [&](vector<ll> &pref, vector<ll> &suff) -> bool {
            int n = pref.size();
            int sum = 0;
            for (int i = 0; i < n - 1; i++) {
                if (pref[i] == suff[i + 1]) return true;
            }
            return false;
        };

        return check_ans(pref_row, suff_row) || check_ans(pref_col, suff_col);
    }
};