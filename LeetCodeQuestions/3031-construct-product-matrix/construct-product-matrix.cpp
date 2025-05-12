class Solution {
public:
    const int MOD = 12345;
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& a) {
        int n = a.size(), m = a[0].size();
        vector<vector<int>> prefix(n, vector<int> (m, 1));
        vector<vector<int>> suffix(n, vector<int> (m, 1));
        vector<vector<int>> ans(n, vector<int> (m, 1));

        long long prod = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                prefix[i][j] = (int)(prod % MOD);
                prod = (prod * a[i][j]) % MOD;
            }
        }

        prod = 1;

        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                suffix[i][j] = (int)(prod % MOD);
                prod = (prod * a[i][j]) % MOD;
            }
        }
    

        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans[i][j] = (int)(1LL * prefix[i][j] * suffix[i][j]) % MOD;

            }
        }
        return ans;
    }
};