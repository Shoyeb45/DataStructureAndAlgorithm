#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

void dfs(vector<int> &ans, vector<int> adj[], int start, int prev) {
    ans[start] = 1;
    for(int node: adj[start]) {
        if(node == prev) {
            continue;
        }
        dfs(ans, adj, node, start);
        ans[start] += ans[node];
    }
}

// Function to calculate the number of nodes in each subtree of given tree
vector<int> countNumOfNodes(vector<int> adj[], int n) {
    vector<int> ans(n + 1, 0);

    dfs(ans, adj, 1, -1);
    return ans;
}


int main() {
    NFS
    
    int n;
    cin >> n;

    vector<int> adj[n + 1];

    for(int i = 0, a, b; i < n - 1; i++) {
        cin >> a >> b;
        adj[a].push_back(b); 
        adj[b].push_back(a); 
    }

    vector<int> numOfNode = countNumOfNodes(adj, n);

    for(int i = 1; i <= n; i++) {
        cout << "Number of nodes in subtree " << i << " : " << numOfNode[i] << "\n";  
    }
    return 0;
}