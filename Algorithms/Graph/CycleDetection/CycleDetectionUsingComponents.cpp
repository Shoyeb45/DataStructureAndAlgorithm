#include<bits/stdc++.h>
using namespace std;

int findNumberOfComponent(vector<vector<int>> &graph) {
    int n = graph.size();
    vector<bool> vis(n, false);

    std::function<void(int)> dfs = [&](int node) {
        vis[node] = true;

        for (auto &neighbor : graph[node]) {
            if (!vis[neighbor]) {
                dfs(neighbor);
            }
        }
    };

    int count = 0;
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            count++;
            dfs(i);
        }
    }

    return count;
}


bool isCycle(vector<vector<int>> &graph, int edges) {
    int c = findNumberOfComponent(graph);

    return edges != graph.size() - c; 
}


int main() {
    int nodes, edges;
    cin >> nodes >> edges;
    vector<vector<int>> graph(nodes);

    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    cout << (isCycle(graph, edges)? "Cycle is present": "Cycle is not present");
}