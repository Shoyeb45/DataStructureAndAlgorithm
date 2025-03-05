class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int u, int v) {
        priority_queue<pair<double, int>> pq;

        vector<double> dist(n + 1, INT_MIN);
        vector<bool> vis(n + 1, false);


        vector<vector<pair<int, double>>> adj(n + 1);
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0], v = edges[i][1];
            double pr = succProb[i];
            adj[u].push_back({v, pr});
            adj[v].push_back({u, pr});
        }

        vis[u] = true;
        pq.push({1, u});

        while (!pq.empty()) {
            double prob = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for (auto x : adj[node]) {
                int ver = x.first;
                double per = x.second;

                if (per * prob > dist[ver]) {
                    dist[ver] = per * prob;
                    cout << prob << "\n";
                    pq.push({dist[ver], ver});
                }
            }
        }

        return (dist[v] == INT_MIN? 0: dist[v]);
    }
};