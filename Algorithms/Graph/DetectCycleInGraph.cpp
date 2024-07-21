#include<bits/stdc++.h>
using namespace std;

#define loop(i, n) for(int i = 0; i < n; i++)
#define range(x) (x).begin(), (x).end()
typedef long long ll;
const ll mod = 1000000007;

// BFS Method to detect Node
bool bfs(int curr, vector<int> adj[], vector<bool> &visited) {
    queue<pair<int, int>> q;
    visited[curr] = 1;
    q.push({curr, -1});
    while(!q.empty()) {
        int node = q.front().first;
        int parent = q.front().first;
        q.pop();

        for(auto adjNode: adj[curr]) {
            if(!visited[adjNode]) {
                q.push({adjNode, node});
            } else if(adjNode != parent) {
                return true;
            }
        }
    }
    return false;
}

bool isCycle(int V, vector<int> adj[]) {
    vector<bool> visited(V);
    loop(i, V) {
        if(bfs(i, adj, visited))
            return true;
    }
    return false;
}

int main() {
    int nodes, edges;
    cin >> nodes >> edges;
    vector<int>  adjacencyList[nodes + 1]; 

    loop(i, edges) {
        int x, y;
        cin >> x >> y;   
        adjacencyList[x].push_back(y);  
        adjacencyList[y].push_back(x);
    }

    cout << (isCycle(nodes, adjacencyList)? "Yes!! There is cylce\n": "No!! There is no cycle\n");
    return 0;
}
