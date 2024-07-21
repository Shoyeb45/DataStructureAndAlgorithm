#include <bits/stdc++.h>
using namespace std;

#define loop(i, n) for (int i = 0; i < n; i++)
#define range(x) (x).begin(), (x).end()
typedef long long ll;
const ll mod = 1000000007;

// Function for sorting the nodes according to their time
void sortNode(vector<vector<int>> &adj, stack<int> &st, vector<bool> &visited, int curr) {
    visited[curr] = 1;
    for (auto node : adj[curr]) {
        if (!visited[node]) {
            visited[node] = 1;
            sortNode(adj, st, visited, node);
        }
    }
    st.push(curr);
}


// Function for dfs traversal
void dfs(vector<vector<int>> &revAdj, vector<bool> &visited, int curr) {
    visited[curr] = 1;
    for (auto node : revAdj[curr]) {
        if (!visited[node]) {
            visited[node] = 1;
            dfs(revAdj, visited, node);
        }
    }
}

// Function for reversing the direction of edges
void reverseDirection(vector<vector<int>> &revAdj, vector<vector<int>> &adj) {
    loop(i, adj.size()) {
        for (int node : adj[i]) {
            revAdj[node].push_back(i);
        }
    }
}

// Main function to calculate number of SCC
int kosaraju(int V, vector<vector<int>> &adj) {
    vector<bool> visited(V, 0);
    stack<int> st;

    loop(i, V) {
        if (!visited[i]) {
            sortNode(adj, st, visited, i);
        }
    }

    vector<vector<int>> revAdj(V);

    reverseDirection(revAdj, adj);

    loop(i, V)
        visited[i] = 0;

    int numOfSCC = 0;
    while (!st.empty()) {
        int curr = st.top();
        st.pop();
        if (!visited[curr]) {
            numOfSCC++;
            dfs(revAdj, visited, curr);
        }
    }
    return numOfSCC;
}


int main() {

    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);

    loop(i, m) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }

    cout << kosaraju(n, adj) << "\n";

    return 0;
}
