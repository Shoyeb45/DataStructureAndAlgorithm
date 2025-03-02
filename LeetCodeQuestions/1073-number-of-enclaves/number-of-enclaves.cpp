class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        int ans = 0;

        auto bfs = [&](int i, int j) -> int {
            queue<pair<int, int>> q;
            q.push(make_pair(i, j));
            grid[i][j] = 1;
            int ans = 1;
            bool flag = true;

            while (!q.empty()) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();

                grid[x][y] = 0;

                for (int k = 0; k < 4; k++) {
                    int nx = x + dx[k], ny = y + dy[k];
                    if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
                        if (grid[nx][ny] == 1) {
                            grid[nx][ny] = 0;
                            ans++;
                            q.push(make_pair(nx, ny));
                        }
                    }
                    else {
                        flag = false;
                    }
                }
            }

            return (flag ? ans: 0);
        };

        // auto print = [&]() -> void {
        //     for (auto x : grid) {
        //         for (auto y : x) {
        //             cout << y << ' ';
        //         }
        //         cout << "\n";
        //     }
        //     cout << '\n';
        // };
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {

                    int x = bfs(i, j);
                    // cout << "x " << x << "\n";
                    // print();
                    ans += x;
                }
            }
        }

        return ans;
    }
};