class Solution {
public:

    int trapRainWater(vector<vector<int>>& a) {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        int n = a.size(), m = a[0].size();

        auto is_valid = [&] (int i, int j) -> bool {
            return i >= 0 && j >= 0 && i < n && j < m;
        };

        vector<vector<bool>> vis(n, vector<bool> (m, false));
        for (int i = 0; i < m; i++) {
            vis[0][i] = vis[n - 1][i] = true;
            pq.push({a[0][i], {0, i}});
            pq.push({a[n - 1][i], {n - 1, i}});
        } 

        for (int i = 1; i < n - 1; i++) {
            vis[i][0] = vis[i][m - 1] = true;
            pq.push({a[i][0], {i, 0}});
            pq.push({a[i][m - 1], {i, m - 1}});
        }

        int ans = 0;

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        while (!pq.empty()) {
            int mn = pq.top().first;
            int x = pq.top().second.first, y = pq.top().second.second;
            pq.pop();


            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k], ny = y + dy[k];

                if (is_valid(nx, ny) && !vis[nx][ny]) {
                    int height = a[nx][ny];
                    vis[nx][ny] = true;

                    if (height >= mn) {
                        pq.push({height, {nx, ny}});
                    }
                    else {
                        pq.push({mn, {nx, ny}});
                        ans += mn - height;
                    }
                }
            }
        }           

        return ans;
    }
};