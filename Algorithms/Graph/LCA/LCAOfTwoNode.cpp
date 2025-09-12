# include<bits/stdc++.h>
using namespace std;

// Given q queries of kind u and v. Find the LCA of two nodes u and v.

// LCA : Let G be a tree. For every query of the form (u, v) we want to find the lowest common 
// ancestor of the nodes u and v, i.e. we want to find a node w that lies on the path from u 
// to the root node, that lies on the path from v to the root node, and if there are multiple 
// nodes we pick the one that is farthest away from the root node. In other words the desired node w is the 
// lowest ancestor of u and v. In particular if u is an ancestor of v, then u is their lowest common ancestor.



// For solving this question eficiently we will use Binary Lifting. 

// Precomputation: Sparse Table
// For every node, we will store all power's of 2 parent.
// sparse_table[i][j] -> for ith node the 2^jth parent, if we exceed the root node store -1.

vector<int> depth;
vector<vector<int>> sparse_table;

int lca(int u, int v) {
    // we'll make sure depth[u] > depth[v]
    if (depth[v] > depth[u]) {
        swap(u, v);
    }

    int difference = depth[u] - depth[v];
    cout << difference << "\n";
    for (int i = 30; i >= 0; i--) {
        // extract bit
        int bit = ((1 << i) & difference);
        if (bit) {
            u = sparse_table[u][i];
        }
    }

    if (u == v) {
        return v;
    }

    for (int i = 30; i >= 0; i--) {
        if (sparse_table[u][i] != sparse_table[v][i]) {
            u = sparse_table[u][i], v = sparse_table[v][i];
        }
    }
    return sparse_table[u][0];
}


void dfs(int u, vector<vector<int>> &adj, int p, int d = 0) {

    depth[u] = d;
    sparse_table[u][0] = p;
    for (int v: adj[u]) {

        if (v != p) {
            dfs(v, adj, u, d + 1);
        }
    }

}

void binary_lifting(vector<vector<int>> &adj, int n, int q) {
    sparse_table.resize(n, vector<int> (31, -1));
    depth.resize(n);

    dfs(0, adj, -1);
    
    // calculating sparse table 
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= 30; j++) {
            if (sparse_table[i][j - 1] != -1) {
                // First we'll find the 2^(j - 1)th parent and 2^(j - 1) parent of that node will be 
                // 2^jth parent of node i. 
                sparse_table[i][j] = sparse_table[sparse_table[i][j - 1]][j - 1];
            }
        }
    }


    while (q--) {
        int u, v;
        cin >> u >> v;
        cout << "LCA(u, v): " << lca(u, v) << "\n"; 
    }
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    for (int i = 0, a, b; i < n - 1; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    int q;
    cin >> q;
    
    binary_lifting(adj, n, q);
}