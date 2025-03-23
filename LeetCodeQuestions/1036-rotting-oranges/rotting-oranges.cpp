class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        queue<pair<pair<int, int>, int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                }
            }
        }

        int ans = 0;
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};


        while (!q.empty()) {
            int x = q.front().first.first;
            int y = q.front().first.second;
            int time = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];

                if (nx >= 0 && ny >= 0 && nx < n && ny < m && grid[nx][ny] == 1) {
                    grid[nx][ny] = 2;
                    q.push({{nx, ny}, time + 1});
                    ans = max(ans, time + 1);
                }
            } 
        }


        for (auto x : grid) {
            for (auto y: x) {
                if (y == 1) {
                    return -1;
                }
            }
        }

        return ans;
    }
};