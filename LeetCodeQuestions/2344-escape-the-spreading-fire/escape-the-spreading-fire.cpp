class Solution {
public:
    int arr[4] = {-1, 1, 0, 0};
    int brr[4] = {0, 0, -1, 1};
    int n, m;

    bool check(int mid, vector<vector<int>>& fireTime, vector<vector<int>>& grid) {
        vector<vector<int>> visited(n, vector<int>(m, 0));
        queue<pair<pair<int, int>, int>> pq;
        pq.push({{0, 0}, 0});
        visited[0][0] = true;

        while (!pq.empty()) {
            int i = pq.front().first.first;
            int j = pq.front().first.second;
            int time = pq.front().second;
            pq.pop();

            if (i == n - 1 && j == m - 1) {
                return time + mid <= fireTime[i][j];
            }

            if (time + mid >= fireTime[i][j]) {
                continue;
            }

            for (int a = 0; a < 4; a++) {
                int ii = i + arr[a];
                int jj = j + brr[a];

                if (ii >= 0 && jj >= 0 && ii < n && jj < m && !visited[ii][jj] && grid[ii][jj] != 2) {
                    visited[ii][jj] = true;
                    pq.push({{ii, jj}, time + 1});
                }
            }
        }
        return false;
    }

    int maximumMinutes(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        queue<pair<pair<int, int>, int>> pq;
        vector<vector<int>> fireTime(n, vector<int>(m, INT_MAX));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    fireTime[i][j] = 0;
                    pq.push({{i, j}, 0});
                }
            }
        }

        while (!pq.empty()) {
            int i = pq.front().first.first;
            int j = pq.front().first.second;
            int level = pq.front().second;
            pq.pop();

            for (int a = 0; a < 4; a++) {
                int ii = i + arr[a];
                int jj = j + brr[a];

                if (ii >= 0 && jj >= 0 && ii < n && jj < m && fireTime[ii][jj] == INT_MAX && grid[ii][jj] != 2) {
                    fireTime[ii][jj] = level + 1;
                    pq.push({{ii, jj}, level + 1});
                }
            }
        }

        int low = 0, high = 1e9, ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (check(mid, fireTime, grid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};
