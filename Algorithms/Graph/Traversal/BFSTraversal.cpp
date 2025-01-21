#include<bits/stdc++.h>
using namespace std;

#define loop(i, n) for(int i = 0; i < n; i++)
#define range(x) (x).begin(), (x).end()
typedef long long ll;
const ll mod = 1000000007;

vector<int> BFSTraversal(int V, vector<int> adj[]) {
        
        vector<bool> visited(V + 1, 0); // Visited array
        vector<int> ans; // Traversal array
        queue<int> q;

        q.push(0);
        visited[0] = 1;

        while(!q.empty()) {
            int curr = q.front();
            q.pop();
            ans.push_back(curr);
            
            for(int i = 0; i < adj[curr].size(); i++) {
                if(!visited[adj[curr][i]]) {
                    q.push(adj[curr][i]);
                    visited[adj[curr][i]] = 1;  // Updating the visited array
                }
            }
        }
        return ans;
    }

int main() {
    
    // BFS Traversal on adjacency list on directed graph
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];

    loop(i, m) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }

    vector<int> bfs = BFSTraversal(n, adj);
    return 0;
}
