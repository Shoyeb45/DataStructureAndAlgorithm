# include<bits/stdc++.h>
using namespace std;


// you are given tree in graph format, and you are given q queries, you have to say the number of edges between 
// u and v.


// if LCA(u, v) = x, then the length from u -> v:
// length(u, v) = length(x, u) + length(x, v)


// For computing the length from lca to u and lca to v. we can precompute the level(or depth) of each node.
// depth[i] -> level or depth of node i.
// Then length(a, b) = |depth[a] - depth[b]|

// Then,
// length(u, v) = depth[u] - depth[x] + depth[v] - depth[x]
// length(u, v) = depth[u] + depth[v] - 2 * depth[x]
// Now the problem is to calculate the LCA(u, v) efficiently.



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

void number_of_edges(vector<vector<int>> &adj, int n, int q) {
    sparse_table.resize(n, vector<int> (31, -1));
    depth.resize(n);

    dfs(0, adj, -1);
    
    // calculating sparse table 
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= 30; j++) {
            if (sparse_table[i][j - 1] != -1) {
                sparse_table[i][j] = sparse_table[sparse_table[i][j - 1]][j - 1];
            }
        }
    }


    while (q--) {
        int u, v;
        cin >> u >> v;
        int x = lca(u, v);
        cout << depth[u] + depth[v] - 2 * depth[x] << "\n"; 
    }
}
int main() {
    int n;
    cin >> n;

    // 0 based indices of the vertex of the tree
    vector<vector<int>> adj(n);

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }
}