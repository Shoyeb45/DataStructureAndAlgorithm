class Solution {
public:
    int maximumMinutes(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        vector<vector<int>> dist(n, vector<int> (m, INT_MAX));
        vector<vector<bool>> vis(n, vector<bool> (m, false));
        
        queue< pair<int, int> > q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    dist[i][j] = 0;
                    vis[i][j] = 1;
                    q.push(make_pair(i, j));                    
                }
            }
        }
        
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k], ny = y + dy[k];

                if (nx >= 0 && ny >= 0 && nx < n && ny < m && grid[nx][ny] == 0 && !vis[nx][ny]) {
                    vis[nx][ny] = 1;
                    dist[nx][ny] = min(dist[nx][ny], dist[x][y] + 1);
                    q.push({nx, ny});
                }
            }    
        }

        function<bool(int)> check = [&](int mid) {
            
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    vis[i][j] = false;
                }
            }

            queue<pair< pair<int, int> , int>> q;
            q.push({{0, 0}, 0});

            bool ans = 0;

            vis[0][0] = 1;
            while (!q.empty()) {
                int x = q.front().first.first, y = q.front().first.second;
                int chk = q.front().second;
                q.pop();
                if (x == n - 1 && y == m - 1 && (dist[x][y] - mid - chk >= 0 || dist[x][y] == -1)) {
                    return true;
                }
                if (dist[x][y] != -1 && dist[x][y] - mid - chk <= 0) {
                    continue;
                }
                for (int i = 0; i < 4; i++) {
                    int nx = x + dx[i], ny = y + dy[i];
                    if (nx >= 0 && ny >= 0 && nx < n && ny < m && grid[nx][ny] != 2 && !vis[nx][ny]) {
                        vis[nx][ny] = 1;
                        q.push({{nx, ny}, chk + 1});
                    }
                }
            }

            return false;
        };

        int low = 0, high = 1e9, ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (check(mid)) {
                ans = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return ans;
    }
};