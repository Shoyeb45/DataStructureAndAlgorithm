class Solution {
public:
    const int MOD = int(1e9) + 7;
    vector<vector<int>> a;
    int n, m, k;

    int f(int i, int j, int sum, vector<vector<vector<int>>>& dp) {
        if (i >= n || j >= m) {
            return 0;
        }
        sum = (sum + a[i][j]) % k;
        if (i == n - 1 && j == m - 1) {
            return sum == 0; 
        }

        if (dp[i][j][sum] != -1) return dp[i][j][sum];

        int right = f(i, j + 1, sum, dp);
        int down = f(i + 1, j, sum, dp);
    
        return dp[i][j][sum] = (right + down) % MOD;
    }

    int numberOfPaths(vector<vector<int>>& grid, int k) {
        a = grid;    
        n = a.size(), m = a[0].size();
        vector dp(n, vector<vector<int>> (m, vector<int> (k, -1)));

        this->k = k;
        for (auto &x: a) {
            for (auto &y: x) {
                y %= k;
            }
        }
        return f(0, 0, 0, dp);
    }
};