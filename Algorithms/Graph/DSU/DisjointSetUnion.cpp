#include<bits/stdc++.h>
using namespace std;

class DisjointSetUnion {
    private:
        vector<int> parents;
        vector<int> height;

    public:
        DisjointSetUnion(int n) {
            parents.resize(n), height.resize(n);
            for(int i = 0; i < n; i++) {
                parents[i] = i;
                height[i] = 0;
            }
        }

        int find(int node) {
            if(parents[node] != node) {
                parents[node] = find(parents[node]);
            }
            return parents[node];
        } 

        void connect(int x, int y) {
            int rootX = find(x);
            int rootY = find(y);

            if(height[rootX] > height[rootY]) {
                parents[rootY] = rootX;
                height[rootX] = max(height[rootX], height[rootY] + 1);
            }
            else {
                parents[rootX] = rootY;
                height[rootY] = max(height[rootY], height[rootX] + 1);
            }
        }

        bool isConnected(int x, int y) {
            return find(x) == find(y);
        }
};