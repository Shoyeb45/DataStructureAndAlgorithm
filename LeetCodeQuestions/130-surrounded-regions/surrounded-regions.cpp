class Solution {
public:
    void solve(vector<vector<char>>& a) {
        int n = a.size(), m = a[0].size();

        auto is_valid = [&](int i, int j) -> bool {
            return i >= 0 && j >= 0 && i < n && j < m;
        };

        vector<vector<bool>> vis(n, vector<bool> (m, false));
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        function<void(int, int)> bfs = [&](int i, int j) {
            queue<pair<int, int>> q;
            vis[i][j] = true;
            q.push({i, j});
            vector<pair<int, int>> indices = {{i, j}};

            bool is_boundary = false;

            while (!q.empty()) {
                int x = q.front().first, y = q.front().second;
                q.pop();
                if (x == n - 1 || y == m - 1 || x == 0 || y == 0) {
                    is_boundary = true;
                }

                for (int k = 0; k < 4; k++) {
                    int nx = x + dx[k], ny = y + dy[k];

                    if (is_valid(nx, ny) && a[nx][ny] == 'O' && !vis[nx][ny]) {
                        vis[nx][ny] = true;
                        indices.push_back({nx, ny});
                        q.push({nx, ny});                        
                    }
                }
            }
            cout << is_boundary << "\n";
            if (!is_boundary) {
                for (auto x : indices) {
                    a[x.first][x.second] = 'X';
                }
            }
        };

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] == 'O' && !vis[i][j]) {
                    cout << i << " " << j << "\n";
                    bfs(i, j);
                }
            }
        }
    }
};