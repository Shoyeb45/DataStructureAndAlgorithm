class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector< vector< pair<int, int>> > adj(n + 1);

        for (auto edge: times) {
            adj[edge[0]].push_back({edge[1], edge[2]});
        }

        vector<int> dist(n + 1, INT_MAX);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        q.push({0, k});
        dist[k] = 0;

        while (!q.empty()) {
            int node = q.top().second;
            int distance = q.top().first;
            q.pop();


            for (auto x : adj[node]) {
                int ver = x.first;
                int wt = x.second;

                if (wt + distance < dist[ver]) {
                    dist[ver] = wt + distance;
                    q.push({dist[ver], ver});
                }
            }
        } 

        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX) {
                return -1;
            }
            ans = max(ans, dist[i]);
        }

        return ans;
    }
};