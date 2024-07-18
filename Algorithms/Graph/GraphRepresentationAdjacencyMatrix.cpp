#include<bits/stdc++.h>
using namespace std;

#define loop(i, n) for(int i = 0; i < n; i++)
#define range(x) (x).begin(), (x).end()
typedef long long ll;
const ll mod = 1000000007;

// Adjacency Matrix representation of undirected Graph 
// If we want to store the directed graph, then just mark adjacencyMat[x][y] = true;

int main() {
    int nodes, edges;
    cin >> nodes >> edges;
    vector<vector<bool>> adjacencyMat(nodes + 1, vector<bool> (nodes + 1, 0));

    loop(i, edges) {
        int x, y;
        cin >> x >> y;   // edge between x - y
        adjacencyMat[x][y] = adjacencyMat[y][x] = true;
    }
    // Space complexity : O(nodes^2) == O(n^2)
    return 0;
}
