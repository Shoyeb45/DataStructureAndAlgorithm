#include<bits/stdc++.h>
using namespace std;

#define loop(i, n) for(int i = 0; i < n; i++)
#define range(x) (x).begin(), (x).end()
typedef long long ll;
const ll mod = 1000000007;

auto init = []() { 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

// Bellman-Ford Algorithm for Directed Graph
vector <int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
    vector<int> distance(V, 1e8);
    distance[S] = 0;
    int iter = V - 1;

    // (nodes - 1) iteration for relaxation of edges
    while(iter--) {
        for(int i = 0; i < edges.size(); i++) {
            int u = edges[i][0], v = edges[i][1], w = edges[i][2];

            // If the going from u -> v is minimum
            if(distance[u] != 1e8 && distance[u] + w < distance[v]) {
                distance[v] = distance[u] + w;  // Update the distance of vth node
            }
        }
    }

    // Last relaxation for detecting cycle
    for(int i = 0; i < edges.size(); i++) {
        int u = edges[i][0], v = edges[i][1], w = edges[i][2];
        
        if(distance[u] != 1e8 &&distance[u] + w < distance[v]) {
            // Cycle exists
            return {-1};
        }
    }

    return distance;
}

int main() {
    int n, m, src;
    vector<vector<int>> adj;
    loop(i, m) {
        int start, end, weight;
        cin >> start >> end >> weight;
        adj.push_back({start, end, weight});
    }

    vector<int> distance = bellman_ford(n, adj, src);

    // Negative cycle
    if(distance.size() == 1 && distance[0] == -1) {
        cout << "Negative cycle detected";
        return 0;
    } 

    // Output Array - minimum distance of all nodes with source node
    loop(i, distance.size()) {
        cout << distance[i] << " ";
    }
    cout << "\n";
    return 0;
}
