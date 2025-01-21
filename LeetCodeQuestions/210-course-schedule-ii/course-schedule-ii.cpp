class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(n);

        for (auto x : prerequisites) {
            adj[x[0]].push_back(x[1]);
        }
        
        vector<int> ans, indegree(n, 0);

        for (int i = 0; i < n; i++) {
            for (auto x : adj[i]) {
                indegree[x]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int currNode = q.front();
            q.pop();
            ans.push_back(currNode);

            for (int x : adj[currNode]) {
                indegree[x]--;
                if (indegree[x] == 0) {
                    q.push(x);
                }
            }
        }
        reverse(ans.begin(), ans.end());
        return (ans.size() != n ? ans = {}: ans);
    }
};