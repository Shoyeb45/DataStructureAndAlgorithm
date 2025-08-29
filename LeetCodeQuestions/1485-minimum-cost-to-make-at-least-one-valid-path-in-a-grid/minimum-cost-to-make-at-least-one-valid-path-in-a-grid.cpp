class Solution {
public:


    int minCost(vector<vector<int>>& grid) {
        
        int n = grid.size(), m = grid[0].size();
        deque<pair<int, int>> dq;

        dq.push_front({n - 1, m - 1});

        // 1 -> right, 2 -> left, 3 -> down, 4 -> up
        vector<vector<int>> d(n, vector<int> (m, INT_MAX));

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, -1, 0, 1};

        auto check = [&](int x, int y) -> int {
            if (x == 0) {
                if (y == -1) {
                    return 1;
                }
                return 2;
            } 

            if (x == -1) {
                return 3;
            }
            return 4;
        };

        d[n - 1][m - 1] = 0;

        int ans = INT_MAX;
        while (!dq.empty()) {
            auto p = dq.front();
            dq.pop_front();


            int i = p.first, j = p.second;


            for (int k = 0; k < 4; k++) {
                int nx = i + dx[k], ny = j + dy[k];
                if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
                    int expected = check(nx - i, ny - j);

                    if (expected == grid[nx][ny] && d[i][j] < d[nx][ny]) {
                        dq.push_front({nx, ny});
                        d[nx][ny] = d[i][j];
                    } else if (d[i][j] + 1 < d[nx][ny]) {
                        dq.push_back({nx, ny});
                        d[nx][ny] = d[i][j] + 1;
                    }
                }
            }
        }

        return d[0][0];
    }
};