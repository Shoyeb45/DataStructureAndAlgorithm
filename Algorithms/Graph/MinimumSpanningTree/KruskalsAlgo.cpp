#include <bits/stdc++.h>
using namespace std;

class DSU {
    vector<int> height, parent;
    public:
    DSU(int n) {
        height.resize(n, 1);
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    
    int find(int x) {
        if (parent[x] != x) {
            return parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    
    void merge(int x, int y) {
        int root_x = find(x), root_y = find(y);
        if (root_x == root_y) return;
        if (height[root_x] > height[root_y]) {
            swap(root_x, root_y);
        }
        height[root_y] += height[root_x];
        parent[root_x] = root_y;
    }        
    
    bool isConnected(int x, int y) {
        return find(x) == find(y);
    }
};

pair<int, vector<vector<int>>> kruskalsMST(int n, vector<vector<int>> &edges) {
    vector<vector<int>> mst;
    sort(edges.begin(), edges.end(), [](const vector<int> &a1, const vector<int> &a2) {
        return a1[2] < a2[2];
    });

    DSU dsu(n);
    int ans = 0;
    for (auto edge : edges) {
        int u = edge[0], v = edge[1], wt = edge[2];
        if (!dsu.isConnected(u, v)) {
            ans += wt;
            dsu.merge(u, v);
            mst.push_back({u, v, wt});
        }    
    }
    return make_pair(ans, mst);
}

int main() {
    int nodes, edges;
    cin >> nodes >> edges;
    vector<vector<int>> edgeList;

    for (int i = 0, u, v, wt; i < edges; i++) {
        cin >> u >> v >> wt;
        edgeList.push_back({u, v, wt});
    }

    pair<int, vector<vector<int>>> res = kruskalsMST(nodes, edgeList);
    vector<vector<int>> mst = res.second;

    cout << "Minimum Spanning Tree Edges ->\n";
    for (auto edge : mst) {
        cout << edge[0] << " - " << edge[1] << " (Weight: " << edge[2] << ")\n";
    }

    cout << "Weight of Minimum Spanning Tree: " << res.first << "\n";
}
