#include<bits/stdc++.h>
using namespace std;


bool isCycle(vector<int> adj[], int nodes, int edges) {
    int nunOfComponents = 0;

    vector<bool> vis(nodes, false);

    std::function<void(int)> dfs = [&](int node) {
        vis[node] = true;

        for (auto neighbour : adj[node]) {
            if (!vis[neighbour]) {
                dfs(neighbour);
            }
        }
    };

    for (int i = 0; i < nodes; i++) {
        if (!vis[i]) {
            dfs(i);
            nunOfComponents++;
        }
    }


    return nodes - nunOfComponents != edges; 
}


int main() {
    return 0;
}   