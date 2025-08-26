# include<bits/stdc++.h>
using namespace std;


// The problem is to find the maximum flow through s -> d, where each edge E(v, u) have 
// some cost, that is C(v, u) -> the maximum allowed flow. And each vertex should follow Kirchoff's law.
// That s summation(incoming flow) = summation(outgoing flow).


/*
# The main Algorithm:


1) Building Residual Graph
-> Build graph from a given network, if cost(u, v) = c and flow(u, v) = f. Then the residual graph will have 
   same vertex and edges, but from u -> v in residual graph, the edge weight will be = c - f, and in v -> u
   the edge weight will be f.
   
2) Finding Auxilary path
-> For given residual graph, find a path from s -> d:
    if found:
        Then there is chance of getting a max network flow. 
        Take minimum edge weight from the found path, and update the flow, i.e., if from u -> v the flow is f and minumum
        edge is w, then the new flow from u -> v will be f + w. Now if the edge is bacward edge, i.e., one that needs to be 
        decreased, then on the flow network we'll decrease the flow by w, i.e., f - w.
    else not found:
        Then you have the maximum flow newtwork. 
*/


pair<vector<int>, long long> find_auxilary_path(int nodes, vector<vector<int>> &graph, map<pair<int, int>, pair<long long, long long>> &network) {
    // cout << "Finding auxilary path\n";
    vector<int> path(nodes, -1);

    queue<int> q;
    q.push(0);

    vector<bool> visited(nodes, false);
    visited[0] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v: graph[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
                path[v] = u;
            }
        }
    }

    if (path[nodes - 1] == -1) {
        return make_pair(path, -1LL);
    } 

    int v = nodes - 1;
    long long min_wt = INT_MAX;
    while (path[v] != -1) {
        int u = path[v];
        
        auto edge = make_pair(u, v);
        if (network.find(edge) != network.end()) {
            auto flows = network[edge];
            min_wt = min(min_wt, flows.second - flows.first);
        } else {
            auto flows = network[edge];
            min_wt = min(min_wt, flows.first);
        }
        v = u;
    }

    return make_pair(path, min_wt);
}

vector<vector<int>> build_residual_graph(int nodes, map<pair<int, int>, pair<long long, long long>> &network) {
    // cout << "Building residual graph\n";
    vector<vector<int>> residual_graph(nodes);

    for (auto edge: network) {
        int u = edge.first.first, v = edge.first.second;
        int flow = edge.second.first, capacity = edge.second.second;

        if (capacity - flow != 0) {
            residual_graph[u].push_back(v);
        }
        if (flow != 0) {
            residual_graph[v].push_back(u);
        }
    }

    return residual_graph;
}

void update_flow(int nodes, long long min_weight, vector<int> &path ,map<pair<int, int>, pair<long long, long long>> &network, vector<vector<int>> &residual_graph) {
    // cout << "Updating the flow.\n";
    int v = nodes - 1;

    while (path[v] != -1) {
        int u = path[v];
        auto edge = make_pair(u, v);

        // if u -> v exists in map, then we can increase
        if (network.find(edge) != network.end()) {
            pair<int, int> flows = network[edge];
            network[edge] = make_pair(flows.first + min_weight, flows.second);
        } else {
            pair<int, int> flows = network[edge];
            network[edge] = make_pair(flows.first - min_weight, flows.second);
        }
        v = u;
    }
} 

void ford_fulkerson_algorithm(int nodes, int edges, map<pair<int, int>, pair<long long, long long>> &network) {
    vector<vector<int>> residual_graph;

    vector<int> path;
    long long minimum_weight = -1;
    
    do {
        // build residual graph.
        residual_graph = build_residual_graph(nodes, network);

        // find minimum path.
        auto temp = find_auxilary_path(nodes, residual_graph, network);
        path = temp.first;
        minimum_weight = temp.second;
        // cout << "min weight: " << minimum_weight << "\n";
        // update the network flow.
        update_flow(nodes, minimum_weight, path, network, residual_graph);

    } while (minimum_weight != -1);
}

int main() {
    // 0-based vertices
    int nodes, edges;
    cin >> nodes >> edges;


    // I am storing as, 
    // [ u, v ] = [ flow, capacity ]
    map< pair<int, int>, pair<long long, long long> > network;

    for (int i = 0, u, v, w; i < edges; i++) {
        cin >> u >> v >> w;
        --u, --v;
        network[make_pair(u, v)] = make_pair(0, w);
    }
    ford_fulkerson_algorithm(nodes, edges, network);

    int flow = 0;
    for (auto it: network) {
        if (it.first.first == 0) {
            flow += it.second.first;
        }
    }

    cout << flow << "\n";

    // for (auto it: network) {
    //     cout << it.first.first << " -> " << it.first.second << "\t";
    //     cout << "flow: " << it.second.first << " , " << "capacity: " << it.second.second << "\n"; 
    // }

    return 0;
}