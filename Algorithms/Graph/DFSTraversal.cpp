#include<bits/stdc++.h>
using namespace std;

#define loop(i, n) for(int i = 0; i < n; i++)
#define range(x) (x).begin(), (x).end()
typedef long long ll;
const ll mod = 1000000007;

// Function for populating dfs array
void dfsTraversal(vector<int> adj[], vector<int> &dfs, vector<bool> &visited, int curr) {
        dfs.push_back(curr);
        visited[curr] = 1;
        
        for(auto node: adj[curr]) {
            if(!visited[node]) {
                dfsTraversal(adj, dfs, visited, node);
            }
        }
}

int main() {
    
    // DFS Traversal undirected graph through adjacency list 
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];

    loop(i, m) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }

    vector<int> dfs;
    vector<bool> visited(n, 0);   // 0 based indexing
    dfsTraversal(adj, dfs, visited, 0);

    // Print dfs array
    loop(i, dfs.size()) {
        cout << dfs[i] << " ";
    }
    cout << "\n";
    return 0;
}
