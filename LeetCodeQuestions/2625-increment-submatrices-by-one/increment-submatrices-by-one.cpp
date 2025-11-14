class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector ans(n, vector<int> (n, 0));
        for (auto& q: queries) {
            int x1 = q[0], y1 = q[1], x2 = q[2], y2 = q[3];
            ans[x1][y1]++;
            if (y2 + 1 < n) {
                ans[x1][y2 + 1]--; 
            }
            if (x2 + 1 < n) {
                ans[x2 + 1][y1]--;
            }
            if (x2 + 1 < n && y2 + 1 < n) {
                ans[x2 + 1][y2 + 1]++;
            }
        }
        for (int i = 1; i < n; i++) {
            ans[0][i] += ans[0][i - 1];
        }
        for (int i = 1; i < n; i++) {
            ans[i][0] += ans[i - 1][0];
        }
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < n; j++) {
                ans[i][j] += (ans[i - 1][j] + ans[i][j - 1]) - ans[i -1][j - 1];
            }
        }
        return ans;
    }
};