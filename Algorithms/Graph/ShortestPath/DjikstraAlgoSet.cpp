#include<bits/stdc++.h>
using namespace std;

#define loop(i, n) for(int i = 0; i < n; i++)
#define range(x) (x).begin(), (x).end()
typedef long long ll;
const ll mod = 1000000007;

vector <int> dijkstra(int V, vector<vector<int>> adj[], int src) {
    // Distance vector - minimum distance
    vector<int> distance(V, 1e9);
    distance[src] = 0;

    // Set for pair of (distance, node)
    set<pair<int, int>> st;
    st.insert({0, src});

    // BFS
    while(!st.empty()) {
        int dist = st.begin() -> first;
        int vert = st.begin() -> second;
        st.erase({dist, vert});

        for(auto it: adj[vert]) {
            int node = it[0], weight = it[1];

            if(weight + dist < distance[node]) {
                // If the distance is not maximum, then delete the pair in set that will be added because the distance would have been updated
                if(distance[node] != 1e9) {
                    st.erase({distance[node], node});
                }
                // Update the distance of adjacent nodes
                distance[node] = weight + dist;
                st.insert({distance[node], node});    
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
