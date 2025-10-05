class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& a) {
        if (a.empty() || a[0].empty()) return {};
        int n = a.size(), m = a[0].size();
        vector<vector<int>> ans;
        vector<vector<bool>> pac(n, vector<bool>(m,false)), atl(n, vector<bool>(m,false));
        queue<pair<int,int>> qP, qA;

        // push Pacific borders (top row, left column)
        for (int j = 0; j < m; ++j) {
            pac[0][j] = true; qP.push({0, j});
        }
        for (int i = 0; i < n; ++i) {
            pac[i][0] = true; qP.push({i, 0});
        }

        // push Atlantic borders (bottom row, right column)
        for (int j = 0; j < m; ++j) {
            atl[n-1][j] = true; qA.push({n-1, j});
        }
        for (int i = 0; i < n; ++i) {
            atl[i][m-1] = true; qA.push({i, m-1});
        }

        auto bfs = [&](queue<pair<int,int>> &q, vector<vector<bool>> &vis) {
            int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
            while (!q.empty()) {
                auto [x, y] = q.front(); q.pop();
                for (int k = 0; k < 4; ++k) {
                    int nx = x + dx[k], ny = y + dy[k];
                    if (nx >= 0 && ny >= 0 && nx < n && ny < m
                        && !vis[nx][ny] && a[nx][ny] >= a[x][y]) {
                        vis[nx][ny] = true;
                        q.push({nx, ny});
                    }
                }
            }
        };

        bfs(qP, pac);
        bfs(qA, atl);

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (pac[i][j] && atl[i][j])
                    ans.push_back({i, j});

        return ans;
    }
};
