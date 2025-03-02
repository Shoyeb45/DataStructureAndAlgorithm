class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        int ans = 0;

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        auto bfs = [&](int i, int j) -> int {
            queue<pair<int, int>> q;
            q.push(make_pair(i, j));
            int ans = 1;
            grid[i][j] = 0;
            while (!q.empty()) {
                int x = q.front().first, y = q.front().second;
                q.pop();

                for (int k = 0; k < 4; k++) {
                    int nx = x + dx[k], ny = y + dy[k];

                    if (nx >= 0 && ny >= 0 && nx < n && ny < m && grid[nx][ny] == 1) {
                        grid[nx][ny] = 0;
                        ans++;
                        q.push(make_pair(nx, ny));   
                    }
                }
            }

            return ans;
        };

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    ans = max(ans, bfs(i, j));
                }
            }
        }

        return ans;
    }
};