class Solution {
public:
    vector<vector<int>> adj;  // Adjacency list
    vector<bool> visited;

    pair<int, int> bfs(int start) {
        queue<int> q;
        q.push(start);
        visited[start] = true;
        
        int edgeCount = 0;
        int nodes = 1;
        
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            
            for (int neighbor : adj[node]) {
                edgeCount++; // Counting each edge
                
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                    nodes++;
                }
            }
        }
        return {edgeCount / 2, nodes};  // Each edge is counted twice
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        adj.resize(n);

        for (auto edge: edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        int ans = 0;
        visited.resize(n);

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                visited[i] = true;
                pair<int, int> x = bfs(i);

                int numOfEdges = x.first;
                int nodes = x.second;

                if (nodes == 1) {
                    ans++;
                    continue;
                }
                if ((nodes * (nodes - 1)) / 2 == numOfEdges) {
                    ans++;
                }
            }
        }
        return ans;
    }
};