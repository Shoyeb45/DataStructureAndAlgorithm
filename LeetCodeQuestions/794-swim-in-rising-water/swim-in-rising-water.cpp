class Solution {
public:
    
    int swimInWater(vector<vector<int>>& a) {
        int n = a.size(), m = a[0].size();
        vector<vector<int>> dist(n, vector<int> (m, INT_MAX));

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>> , greater<pair<int, pair<int, int>>>> pq;

        dist[0][0] = a[0][0];
        pq.push({dist[0][0], {0, 0}});

        int dx[] = {1, 0, 0, -1};
        int dy[] = {0, -1, 1, 0};

        while (!pq.empty()) {
            int d = pq.top().first;
            int x = pq.top().second.first, y = pq.top().second.second;
            pq.pop();

            for (int k = 0; k < 4; k++) {
                int nx = dx[k] + x, ny = dy[k] + y;

                if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
                    if (max(d, a[nx][ny]) < dist[nx][ny]) {
                        dist[nx][ny] = max(d, a[nx][ny]);
                        pq.push({dist[nx][ny], {nx, ny}});
                    }
                }
            }
        }
        return dist[n - 1][m - 1];
    }
};