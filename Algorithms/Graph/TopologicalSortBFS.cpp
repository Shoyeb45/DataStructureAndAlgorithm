#include<bits/stdc++.h>
using namespace std;

#define loop(i, n) for(int i = 0; i < n; i++)
#define range(x) (x).begin(), (x).end()
typedef long long ll;
const ll mod = 1000000007;

vector<int> topoSort(int V, vector<int> adj[]) {
	// code here
	vector<int> indegree(V), ans;
    for(int i = 0; i < V; i++) {
        for(auto x: adj[i]) {
            indegree[x]++;
        }
    }

    queue<int> q;
    loop(i, V) {
        if(indegree[i] == 0) {
            q.push(i);
        }
    }

    while(!q.empty()) {
        int node = q.front();
        q.pop();
        ans.push_back(node);

        for(auto x: adj[node]) {
            indegree[x]--;
            if(indegree[x] == 0) {
                q.push(x);
            }
        }
    }
    return ans;
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

    loop(i, ans.size())
        cout << ans[i] << ' ';
    cout << "\n";

    return 0;
}
