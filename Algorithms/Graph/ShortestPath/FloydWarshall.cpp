#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> floydWarshall(vector<vector<pair<int, int>>> &adj) {
    int n = adj.size();
    vector<vector<int>> dist(n, vector<int> (n, INT_MAX));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                distance[i][j] = 0;   
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (auto x : adj[i]) {
            distance[i][x.first] = x.second; 
        }
    }

    for (int via = 0; via < n; via++) {
        for (int i = 0; i < n; i++) {
            if (i == via) {
                continue;
            }
            for (int j = 0; j < n; j++) {
                if (j == via || distance[i][via] == INT_MAX || distance[via][j] == INT_MAX) {
                    continue;
                }

                distance[i][j] = min(distance[i][j], distance[i][via] + distance[via][j]);
            }
        }
    }


    return distance;
}

int main() {
    
    return 0;
}