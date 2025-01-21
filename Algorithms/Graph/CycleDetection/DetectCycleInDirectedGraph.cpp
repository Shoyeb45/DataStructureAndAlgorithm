#include<bits/stdc++.h>
using namespace std;


// Helper function for dfs
bool dfs(int currNode, vector<vector<int>> &adj, vector<bool> &vis, vector<int> &pathVisited) {
    vis[currNode] = true;
    pathVisited[currNode] = 1;
    
    for (int node: adj[currNode]) {
        if (!vis[node]) {
            if (dfs(node, adj, vis, pathVisited)) {
                return true;
            }
        }
        
        if (pathVisited[node]) {
            return true;
        }
    }
    pathVisited[currNode] = 0;
    return false;
}

/// Function to detect cycle in a directed graph uing DFS.
bool isCyclic(int V, vector<vector<int>> adj) {
    vector<bool> vis(V, false);
    vector<int> pathVisited(V, 0);
    
    for (int i = 0; i < V; i++) {
        if (!vis[i] && dfs(i, adj, vis, pathVisited)) {
            return true;
        }
    }
    return false;
}


// -------------------------------------------- Cycle detection using BFS ----------------------------------------

bool isCyclicUsingBFS(int V, vector<vector<int>> &adj) {
    vector<int> indegree(V, 0);

    for (int i = 0; i < V; i++) {
        for (auto node: adj[i]) {
            indegree[node]++;
        }
    }

    queue<int> q;

    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    int topoElements = 0;
    while (!q.empty()) {
        int currNode = q.front();
        q.pop();
        topoElements++;

        for (int node: adj[currNode]) {
            indegree[node]--;
            if (indegree[node] == 0) {
                q.push(node);
            }
        }
    }

    return topoElements != V;
}


int main() {
    int nodes, edges;
    cin >> nodes >> edges;
    vector<vector<int>>  adjacencyList; 

    for (int i = 0; i < edges; i++) {
        int x, y;
        cin >> x >> y;   
        adjacencyList[x].push_back(y);  
        adjacencyList[y].push_back(x);
    }

    cout << (isCyclic(nodes, adjacencyList)? "Yes!! There is cylce\n": "No!! There is no cycle\n");
    return 0;
}
