#include<bits/stdc++.h>
using namespace std;

#define loop(i, n) for(int i = 0; i < n; i++)
#define range(x) (x).begin(), (x).end()
typedef long long ll;
const ll mod = 1000000007;

// Adjacency List representation of undirected Graph 
// If we want to store the directed graph, then just push y in adjacencyList[x]

int main() {
    int nodes, edges;
    cin >> nodes >> edges;
    vector<int>  adjacencyList[nodes + 1]; 

    loop(i, edges) {
        int x, y;
        cin >> x >> y;   // edge between x - y
        adjacencyList[x].push_back(y);  
        adjacencyList[y].push_back(x);
    }
    // Space complexity : O(2 * Edges) == O(Edges) = O(m)
    return 0;
}
