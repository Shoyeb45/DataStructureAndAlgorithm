class Solution {
public:

    vector<vector<int>> FloydWarshall(vector<vector<int>> &edges, int n) {
        vector<vector<int>> dist(n, vector<int> (n, 1e9));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) {
                    dist[i][j] = 0;
                }
            }
        }

        for (auto edge: edges) {
            dist[edge[0]][edge[1]] = edge[2];
            dist[edge[1]][edge[0]] = edge[2];
        }

        for (int via = 0; via < n; via++) {
            for (int i = 0; i < n; i++) {

                for (int j = 0; j < n; j++) {
          

                    dist[i][j] = min(dist[i][j], dist[i][via] + dist[via][j]);
                }
            }
        }

        return dist;
    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist = FloydWarshall(edges, n);


        int ans = -1;
        int numOfNeighbours = INT_MAX;
        for (int i = 0; i < n; i++) {
            int temp = 0;
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    temp += (dist[i][j] <= distanceThreshold);
                }
            }

            if (temp < numOfNeighbours) {
                numOfNeighbours = temp;
                ans = i;
            }
            else if (temp == numOfNeighbours) {
                ans = max(i, ans);
            }
        }

        return ans;
    }
};