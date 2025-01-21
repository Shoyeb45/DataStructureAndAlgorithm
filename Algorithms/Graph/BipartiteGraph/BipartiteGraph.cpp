#include<bits/stdc++.h>
using namespace std;

/// @brief Finding if graph is bipartite or not using bfs
/// @param adj : adjacency list of graph
/// @return true or false
bool isBipartiteBFS(vector<vector<int>>& adj) {
    int v = adj.size();
    
    vector<int> color(v, -1);
    
    vector<bool> vis(v, 0);
    
    for (int i = 0; i < v; i++) {
        if (!vis[i]) {
            vis[i] = true;
            queue<int> q;
            q.push(i);
            color[i] = 0;
            
            while (!q.empty()) {
                int node = q.front();
                q.pop();
                
                for (auto neighbour : adj[node]) {
                    if (!vis[neighbour]) {
                        vis[neighbour] = true;
                        q.push(neighbour);
                        color[neighbour] = 1 - color[node];
                    }
                    else if (color[neighbour] == color[node]) {
                        return false;
                    }
                }
            }
            
        }    
    }
    
    return true;
}

/// @brief Helper function to perform DFS
/// @param i   : Current node
/// @param vis : Visited array to keep track of visited nodes
/// @param adj : adjacency list of graph
/// @param color : color of node
/// @return 
bool dfs(int i, vector<bool>& vis, vector<vector<int>> &adj, vector<int> &color) {
    vis[i] = true;
    bool ans = true;
    
    for (auto x : adj[i]) {
        if (!vis[x]) {
            vis[x] = 1;
            color[x] = 1 - color[i];
            ans &= dfs(x, vis, adj, color);
        }
        else if (color[x] == color[i]) {
            return false;
        }
    }
    return ans;
}

/// @brief Finding if graph is bipartite or not using DFS
/// @param adj : adjacency list of graph
/// @return true or false
bool isBipartiteDFS(vector<vector<int>>& adj) {
    int v = adj.size();
    vector<bool> vis(v, false);
    vector<int> color(v, -1);
    
    bool ans = true;
    for (int i = 0; i < v; i++) {
        if (!vis[i]) {
            color[i] = 0;
            ans &= dfs(i, vis, adj, color);
        }
    }
    return ans;
}

int main() {
    
    int nodes, edges;
    cin >> nodes >> edges;
    vector<vector<int>> adj(nodes);

    for (int i = 0, a, b; i < edges; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    cout << (isBipartiteBFS(adj)? "Graph is Bipartite" : "Graph is not bipartite") << "\n";
    return 0;
}