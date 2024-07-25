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

vector <int> dijkstra(int V, vector<vector<int>> adj[], int S) {
    vector<int> distance(V, 1e9);
    // Initializing min heap
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, S}); // Inserting source node into min-heap
    distance[S] = 0;

    while(!pq.empty()) {
        int dist = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        // Traversing adjacent nodes
        for(auto it: adj[node]) {
            int edgeWeight = it[1];
            int vertex = it[0];

            // Checking for minimum distance in neighbour vertex
            if(dist + edgeWeight < distance[vertex]) {
                distance[vertex] = dist + edgeWeight;
                pq.push({distance[vertex], vertex}); // Push updated vertex
            }
        }
    }

    return distance;
}

int main() {
    int n, m, src;
    vector<vector<int>> adj[n];
    loop(i, m) {
        int start, end, weight;
        cin >> start >> end >> weight;
        adj[start].push_back({end, weight});
        adj[end].push_back({start, weight});
    }

    vector<int> distance = dijkstra(n, adj, src);

    // Output Array - minimum distance of all nodes with src node
    loop(i, distance.size()) {
        cout << distance[i] << " ";
    }
    cout << "\n";
    return 0;
}
