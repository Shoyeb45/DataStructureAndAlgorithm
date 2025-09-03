# include<bits/stdc++.h>
using namespace std;

// Articulation point: Deleting a vertex, the number of connected components will be greater than 1
// Articulation Bridges: Deleteing a edge, the number of connected components will be > 1


int d_time = 1; 
vector<int> discovery_time, lowest_time;
vector<pair<int, int>> articulation_bridges;
vector<bool> articulation_points;


void dfs(vector<vector<int>> &adj, vector<bool> &vis, int u, int parent) {
    vis[u] = true;
    lowest_time[u] = discovery_time[u] = d_time++;

    int child = 0;

    for (int v: adj[u]) {
        if (!vis[v]) {
            child++;
            dfs(adj, vis, v, u);
            lowest_time[u] = min(lowest_time[u], lowest_time[v]);

            // articulation bridges
            if (lowest_time[v] > discovery_time[u]) {
                bridges.push_back({u, v})
            }

            // articulation point
            if (lowest_time[v] >= discovery_time[u]) {
                articulation_points[u] = true;
            }
        } else if (parent != v) {
            // backward edge
            lowest_time[u] = min(lowest_time[u], discovery_time[v]);
        }
    }
    if (parent == -1) {
        if (child == 1) {
            articulation_points[u] = false; 
        } else {
            articulation_points[u] = true;
        }
    }
}

// 0 based vertex
void find_number_of_articulation_point_and_bridge(vector<vector<int>> &adj, int n) {
    discovery_time.resize(n), lowest_time.resize(n);
    articulation_points.resize(n);

    vector<bool> vis(n, false);
    dfs(adj, vis, 0, -1);
}