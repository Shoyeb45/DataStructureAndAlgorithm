class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> adj[n];

        for (auto ed : edges) {
            adj[ed[0]].push_back(ed[1]);
            adj[ed[1]].push_back(ed[0]);
        }


        queue<int> q;
        vector<bool> vis(n, false);
        vis[source] = 1;
        q.push(source);

        while (!q.empty()) {
            int x = q.front();
            q.pop();
            if (x == destination) {
                return true;
            }
            
            for (auto nei : adj[x]) {
                if (!vis[nei]) {
                    vis[nei] = 1;
                    q.push(nei);
                }
            }
        }

        return false;
    }
};