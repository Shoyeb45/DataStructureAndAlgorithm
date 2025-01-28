class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        vector<pair<int, int>> waterCell;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] > 0) {
                    waterCell.push_back({i, j});
                }
            }
        }

        int ans = 0;

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        vector<vector<bool>> visited(grid.size(), vector<bool> (grid[0].size(), false));

        auto getEle = [&](pair<int, int> &idx) -> int {
            return grid[idx.first][idx.second];
        };

        auto maximumFish = [&](pair<int, int> ind) -> int {
            queue<pair<int, int>> q;
            q.push(ind);

            visited[ind.first][ind.second] = true;
            int ans = getEle(ind);

            while (!q.empty()) {
                pair<int, int> idx = q.front();
                q.pop();
                
                for (int k = 0; k < 4; k++) {
                    int x = idx.first + dx[k], y = idx.second + dy[k];

                    if (x >= 0 && y >= 0 && x < grid.size() && y < grid[0].size() && !visited[x][y] && grid[x][y] > 0) {
                        q.push({x, y});
                        ans += grid[x][y];
                        // cout << x << " " << y << "\n";
                        visited[x][y] = true;
                    }
                }
            }

            return ans;
        };

        for (auto x : waterCell) {
            if (!visited[x.first][x.second]) {
                ans = max(ans, maximumFish(x));
            }
        }

        return ans;
    }
};