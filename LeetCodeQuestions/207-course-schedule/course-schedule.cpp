class Solution {
public:
    bool isCycle(int n, vector<vector<int>> &adj) {
        vector<int> indegree(n, 0);
        
        for (int i = 0; i < n; i++) {
            for (auto node: adj[i]) {
                indegree[node]++;   
            }
        }
        
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        
        int ans = 0;
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            ans++;
            for (int node: adj[x]) {
                indegree[node]--;
                if (indegree[node] == 0) {
                    q.push(node);
                }
            }
        }
        return ans != n;
    }

    bool canFinish(int N, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(N);
        
        for (auto x : prerequisites) {
            adj[x[0]].push_back(x[1]);
        }
            
        return !isCycle(N, adj);
    }
};