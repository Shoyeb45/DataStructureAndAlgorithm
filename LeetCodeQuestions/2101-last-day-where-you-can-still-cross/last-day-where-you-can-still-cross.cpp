int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};


class Solution {
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        for (auto &x: cells)
            x[0]--, x[1]--;

        vector<vector<int>> mat(row, vector<int> (col, 0));
        vector<vector<bool>> vis(row, vector<bool> (col, false));
        queue<pair<int, int>> q;

        int low = 1, high = cells.size();
        int ans = 0;

        auto check = [&](int mid) -> bool {
            for (int i = 0; i < row; i++)
                for (int j = 0; j < col; j++)
                    mat[i][j] = 0, vis[i][j] = false;
            while (!q.empty()) 
                q.pop();

            for (int i = 0; i < mid; i++) 
                mat[cells[i][0]][cells[i][1]] = 1;

            for (int i = 0; i < col; i++) 
                if (mat[0][i] == 0) 
                    q.push(make_pair(0, i));
            
            while (!q.empty()) {
                auto [x, y] = q.front();
                q.pop();

                if (x == row - 1)
                    return true;
                
                for (int k = 0; k < 4; k++) {
                    int nx = x + dx[k], ny = y + dy[k];

                    if (nx < 0 || ny < 0 || nx >= row || ny >= col || mat[nx][ny] == 1) continue;

                    if (!vis[nx][ny]) {
                        q.push(make_pair(nx, ny));
                        vis[nx][ny] = true;
                    }
                }
            }

            return false;
        };

        while (low <= high) {
            int mid = (low + high) / 2;
            // cout << mid << "\n";
            if (check(mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};