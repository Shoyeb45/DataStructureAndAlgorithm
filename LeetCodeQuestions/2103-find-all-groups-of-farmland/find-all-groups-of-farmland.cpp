class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        auto bfs = [&](int i, int j) -> vector<int> {
            vector<int> ans = {i, j};
            queue<pair<int, int>> q;
            q.push(make_pair(i, j));
            grid[i][j] = 0;

            int _x = i, _y = j;

            while (!q.empty()) {
                int x = q.front().first, y = q.front().second;
                q.pop();

                grid[x][y] = 0;

                for (int k = 0; k < 4; k++) {
                    int nx = x + dx[k], ny = y + dy[k];

                    if (nx >= 0 && ny >= 0 && nx < n && ny < m && grid[nx][ny] == 1) {
                        grid[nx][ny] = 0;
                        _x = max(_x, nx), _y = max(_y, ny);
                        q.push(make_pair(nx, ny));
                    }
                } 
            } 
            ans.push_back(_x), ans.push_back(_y);

            return ans;
        };


        vector<vector<int>> ans;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    vector<int> temp = bfs(i, j);
                    ans.push_back(temp);
                }
            }
        }

        return ans;
    }
};