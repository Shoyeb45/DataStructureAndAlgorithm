#include <bits/stdc++.h>
using namespace std;

#define loop(i, n) for (int i = 0; i < n; i++)

void dfs(int currVertex, vector<pair<int, int>> adj[], stack<int> &topo, vector<bool> &vis) {
    vis[currVertex] = 1;

    for (auto it : adj[currVertex]) {
        if (!vis[it.first]) {
            dfs(it.first, adj, topo, vis);
        }
    }
    topo.push(currVertex);
}

vector<int> shortestPath(vector<pair<int, int>> adj[], int N) {
    // 1. Perform topo sort
    stack<int> topo;
    vector<bool> vis(N, 0);
    for (int i = 0; i < N; i++) {
        if (!vis[i]) {
            dfs(i, adj, topo, vis);
        }
    }

    vector<int> distance(N, INT_MAX);
    int src = 0;
    distance[src] = 0;

    // 2. Check distances
    while (!topo.empty()) {
        int node = topo.top();
        topo.pop();

        if (distance[node] != INT_MAX) {
            for (auto it : adj[node]) {
                int ver = it.first;
                int dist = it.second;

                if (distance[node] + dist < distance[ver]) {
                    distance[ver] = distance[node] + dist;
                }
            }
        }
    }
    // If vertex is unreachable, assign it to -1
    for (int i = 0; i < N; i++) {
        if (distance[i] == INT_MAX) {
            distance[i] = -1;
        }
    }
    return distance;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> adj[n];

    loop(i, m) {
        int x, y, z;
        cin >> x >> y >> z;
        adj[x].push_back({y, z});
    }

    vector<int> distances = shortestPath(adj, n);
    for (int i = 0; i < n; i++) {
        cout << "Distance from source to vertex " << i << ": " << distances[i] << endl;
    }

    return 0;
}
