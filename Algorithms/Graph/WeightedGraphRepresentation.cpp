#include<bits/stdc++.h>
using namespace std;

#define loop(i, n) for(int i = 0; i < n; i++)
#define range(x) (x).begin(), (x).end()
typedef long long ll;
const ll mod = 1000000007;

class Node {
public:
    int x;
    int y;
    int weight;
    Node() {
        x = y = weight = 0;
    }
};

// Adjacency Matrix representation of weighted undirected Graph 
void adjacencyUpdateMatrix(vector<vector<int>> &a, vector<Node> edge) {
    loop(i, edge.size()) {
        a[edge[i].x][edge[i].y] = a[edge[i].y][edge[i].x] = edge[i].weight;
    }
}

// Adjacency List representation of weighted directed Graph 
void adjacencyUpdateList(vector<vector<pair<int, int>>> &a, vector<Node> edge) {
    loop(i, edge.size()) {
        a[edge[i].x].push_back(make_pair(edge[i].y, edge[i].weight));
    }
}


int main() {
    int nodes, edges;
    cin >> nodes >> edges;
    vector<Node> edge(edges); 
    loop(i, edges) {
        cin >> edge[i].x >> edge[i].y >> edge[i].weight;
    }

    // Matrix for storing graph
    vector<vector<int>> adjacencyMat(nodes + 1, vector<int> (nodes + 1, 0));

    // Vector-pair for storing graph in adjacency list
    vector<vector<pair<int, int>>> adjacencyList(edges + 1);

    adjacencyUpdateMatrix(adjacencyMat, edge);
    adjacencyUpdateList(adjacencyList, edge);
    return 0;
}
