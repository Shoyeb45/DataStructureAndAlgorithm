class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        if (grid[0][0] != 0) {
            return false;
        }
        int n = grid.size();
        int dx[] = {1, 2, -1, -2, -1,  1, 2, -2};
        int dy[] = {2, 1, -2, -1,  2, -2, -1, 1};        

        queue<pair<int, int>> q;
        
        q.push({0, 0});
        int target = 1;

        function<bool(int, int)> valid = [&](int x, int y) {
            return x >= 0 && y >= 0 && x < grid.size() && y < grid[0].size();
        };

        while (!q.empty()) {
            int x = q.front().first, y = q.front().second;
            q.pop();

            bool chk = true;
            for (int i = 0; i < 8; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                
                if (valid(nx, ny) && grid[nx][ny]) {
                    if (grid[nx][ny] == target) {
                        q.push({nx, ny});
                        cout << nx << " " << ny << "\n";
                        if (target == n * n - 1) {
                            return true;
                        }
                        target++;
                        chk = false;
                        break;
                    }
                } 
            }
            if (chk) {
                return false;
            }

        }

        return true;
    }
};