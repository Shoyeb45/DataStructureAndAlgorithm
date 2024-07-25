#include <bits/stdc++.h>
using namespace std;

#define loop(i, n) for (int i = 0; i < n; i++)

 vector<int> shortestPath(vector<pair<int, int>> adj[], int N, int src){
        
        queue<int> q;
        q.push(src);
        vector<int> distance(N, INT_MAX);
        distance[src] = 0;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            
            for(auto ver: adj[node]) {
                if(distance[node] + ver.second < distance[ver.first]) {
                    distance[ver.first] = distance[node] + 1;
                    q.push(ver.first);
                }
            }
        }
        
        for(int i = 0; i < N; i++) {
            if(distance[i] == INT_MAX) {
                distance[i] = -1;
            }
        }
        return distance;
    }

int main() {
    int n, m, src;
    cin >> n >> m >> src;
    vector<pair<int, int>> adj[n];

    loop(i, m) {
        int x, y, z;
        cin >> x >> y >> z;
        adj[x].push_back({y, z});
        adj[y].push_back({x, z});
    }

    vector<int> distances = shortestPath(adj, n, src);
    for (int i = 0; i < n; i++) {
        cout << "Distance from source to vertex " << i << ": " << distances[i] << endl;
    }

    return 0;
}
