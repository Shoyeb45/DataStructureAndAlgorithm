class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int n = mat.size(), m = mat[0].size();

        int k = min(n, m);

        vector<vector<int>> pref(n + 1, vector<int> (m + 1));

        for (int i = 0; i < n; i++)
            pref[i + 1][1] += pref[i][1] + mat[i][0];
        

        for (int j = 1; j < m; j++) 
            pref[1][j + 1] += pref[1][j] + mat[0][j];
        
        for (int i = 2; i <= n; i++) {
            for (int j = 2; j <= m; j++) {
                pref[i][j] = mat[i - 1][j - 1] + pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];
            }
        }

        int ans = 0;

        auto find_sum = [&](int i, int j, int sz) -> int {
            int x = i + sz, y = j + sz;
            int sum = pref[x][y] - pref[i - 1][y] - pref[x][j - 1] + pref[i - 1][j - 1];
            return sum;
        };

        for (int sz = 0; sz <= k; sz++) {
            for (int i = 0; i < n - sz; i++) {
                for (int j = 0; j < m - sz; j++) {
                    int sum = find_sum(i + 1, j + 1, sz);
                    // cout << i << " " << j << "\n" << i + sz << " " << j + sz << "\n";
                    // cout << sum << "\n";
                    if (sum <= threshold) 
                        ans = max(ans, sz + 1);
                }
            }
        } 

        return ans;
    }
};