#include<bits/stdc++.h>
using namespace std;

#define loop(i, n) for(int i = 0; i < n; i++)
#define range(x) (x).begin(), (x).end()
typedef long long ll;
const ll mod = 1000000007;

void dfs(vector<int> adj[], vector<bool> &vis, vector<int> &topoSort, int vertex) {
	vis[vertex] = 1;
	for(auto node: adj[vertex]) {
	    if(!vis[node]) {
	        dfs(adj, vis, topoSort, node);
	    }
	}
	topoSort.push_back(vertex);
}

vector<int> topoSort(int V, vector<int> adj[]) {
	// code here
	vector<bool> vis(V, 0);
	vector<int> topoSort;
	    
	for(int i = 0; i < V; i++) {
	    if(!vis[i]) {
	        dfs(adj, vis, topoSort, i);
	    }
	}
	reverse(topoSort.begin(), topoSort.end());
	return topoSort;
}
int main() {
    int n, m;
    cin >> n >> m;
    vector<int>  adj[n]; 

    loop(i, m) {
        int x, y;
        cin >> x >> y;   
        adj[x].push_back(y);  
    }
    
    vector<int> ans = topoSort(n, adj);

    loop(i, n)
        cout << ans[i] << ' ';
    cout << "\n";

    return 0;
}
