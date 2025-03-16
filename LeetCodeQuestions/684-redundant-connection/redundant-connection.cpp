class DSU {
vector<int> parent, height;
public:
    DSU(int n) {
        parent.resize(n);
        height.resize(n, 1);
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

        if (height[root_x] > height[root_y]) {
            swap(root_x, root_y);
        }
        height[root_x] += height[root_y];
        parent[root_x] = root_y;
    }

    bool isConnected(int x, int y) {
        return find(x) == find(y);
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DSU dsu(n);


        for (auto edge: edges) {
            int x = edge[0] - 1, y = edge[1] - 1;

            if (!dsu.isConnected(x, y)) {
                dsu.merge(x, y);
            }
            else {
                return edge;
            }
        }

        return {};
    }
};