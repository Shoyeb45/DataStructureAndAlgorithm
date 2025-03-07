class DSU {
    vector<int> height, parent;
public: 
    
    DSU(int n) {
        height.resize(n, 1), parent.resize(n);
        
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
        
        if (height[root_x] < height[root_y]) {
            swap(root_x, root_y);
        }
        height[root_x] += height[root_y];
        parent[root_x] = parent[root_y];
    }
    
    bool isConnected(int x, int y) {
        return find(x) == find(y);
    }
    
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<vector<int>> edges;
        int n = points.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                edges.push_back({i, j, dist});
            }
        }

        sort(edges.begin(), edges.end(), [&](vector<int> &a1, vector<int> &a2) {
            return a1[2] < a2[2];
        }); 

        int ans = 0;
        DSU dsu(n);
        for (auto edge: edges) {
            if (!dsu.isConnected(edge[0], edge[1])) {
                ans += edge[2];
                dsu.merge(edge[0], edge[1]);
            }
        }

        return ans;
    }
};