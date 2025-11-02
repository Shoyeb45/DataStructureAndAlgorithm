class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        swap(n, m);
        // 1 -> Guard, 2 -> Wall
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for (auto g: guards) {
            mat[g[0]][g[1]] = 1;
        }
        for (auto w: walls) {
            mat[w[0]][w[1]] = 2;
        }
        queue<pair<pair<int, int>, pair<int, int>>> q;
        vector<vector<bool>> vis(n, vector<bool> (m, false));

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        for (auto g: guards) {
            mat[g[0]][g[1]] = 2;
            for (int k = 0; k < 4; k++) {
                int nx = g[0] + dx[k], ny = g[1] + dy[k];
                if (nx < 0 || ny < 0 || nx >= n || ny >= m) {
                    continue;
                }
                q.push(make_pair(make_pair(g[0], g[1]), make_pair(dx[k], dy[k])));
            }
        }


        while (!q.empty()) {
            int x = q.front().first.first, y = q.front().first.second;
            int d_x = q.front().second.first, d_y = q.front().second.second;
            q.pop();

            int nx = x + d_x, ny = y + d_y;
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) {
                continue;
            }
            if (mat[nx][ny] == 2) {
                continue;
            }
        
            mat[nx][ny] = 1;
            q.push(make_pair(make_pair(nx, ny), make_pair(d_x, d_y)));
            vis[nx][ny] = true;
        }
        int ans = 0;
        for (auto x: mat) {
            for (auto y: x) {
                ans += (y == 0);
            }
        }
        return ans;
    }
};