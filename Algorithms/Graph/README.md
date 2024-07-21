# Graph Algorithms

## Theory part

1. Graph Representation

   a. [Adjancency Matrix](./GraphRepresentationAdjacencyMatrix.cpp)

   b. [Adjacency List](./GraphRepresentationAdjacencyList.cpp)

   c. [Weighted Graph Representation](./WeightedGraphRepresentation.cpp)

2. Traversal

   a. [BFS Traversal](./BFSTraversal.cpp)

   b. [DFS Traversal](./DFSTraversal.cpp)


3. Detecting Cycle In Graph

    1. Undirected Graph

        a. [Problem Link](https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=detect-cycle-in-an-undirected-graph)

        b. [Solution using BFS and DFS](./DetectCycleInGraph.cpp)
        
    2. Directed Graph

3. Strongly Connected Components

    a. [Kosraju's Algorithm - Link](https://www.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=strongly-connected-components-kosarajus-algo)

    b. [Kosaraju's Algorithm - Solution](./Kosaraju'sAlgo.cpp)
## Practice Question

1. [Number of Provinces](https://www.geeksforgeeks.org/problems/number-of-provinces/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=number_of_provinces) - GFG

   solution :

   ![Number of Provinces](./Images/image.png)

2. [Flood Fill Alogrithm](https://www.geeksforgeeks.org/problems/flood-fill-algorithm1856/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=flood-fill-algorithm)

   Solution(BFS):
   ![BFS](./Images/ffBFS.png)

   Solution(DFS):
   ![DFS](./Images/ffDFS.png)

3. [Rotten Oranges - GFG](https://www.geeksforgeeks.org/problems/rotten-oranges2536/1)

   [Rotting Oranges - LeetCode](https://leetcode.com/problems/rotting-oranges/)

   Solution:

```
#define loop(i, n) for(int i = 0; i < n; i++)

class Solution  {
    public:
    //Function to find minimum time required to rot all oranges.
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int n = grid.size(), m = grid[0].size();

        queue<pair<int, int>> q;

        int total = 0;
        loop(i, n) {
            loop(j, m) {
                if(grid[i][j] == 2) {
                    q.push({i, j});
                }

                if(grid[i][j] != 0) {
                    total++;
                }
            }
        }

        if(q.size() == n * m) {
            return 0;
        }

        int reqTime = 0, rottenOranges = 0;

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        while(!q.empty()) {
            int currRottenOrange = q.size();
            rottenOranges += currRottenOrange;

            while(currRottenOrange--) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();

                loop(i, 4) {
                    int nx = x + dx[i], ny = y + dy[i];
                    if(nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == 1) {
                        grid[nx][ny] = 2;
                        q.push({nx, ny});
                    }
                }
            }
            if(!q.empty())
                reqTime++;
        }


        if(total == rottenOranges) {
            return reqTime;
        }
        return -1;
    }
};
```

4. Distance of nearest cell having 1/0

    - [Leetcode - 01 Matrix](https://leetcode.com/problems/01-matrix/description/)
    - [GFG - Distance of nearest cell having 1](https://www.geeksforgeeks.org/problems/distance-of-nearest-cell-having-1-1587115620/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=distance-of-nearest-cell-having-1)

Solutions:
<details>
        <summary>Leetcode</summary>

```
#define loop(i, n) for(int i = 0; i < n; i++)

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        int dx[] = {-1, +1, 0, 0};
        int dy[] = {0, 0, -1, +1};

        vector<vector<int>> ans(n, vector<int>(m));
        vector<vector<bool>> visited(n, vector<bool>(m));

        queue<pair<pair<int, int>, int>> q;

        loop(i, n) {
            loop(j, m) {
                if(mat[i][j] == 0) {
                    visited[i][j] = 1;
                    q.push(make_pair(make_pair(i, j), 0));
                }
            }
        }

        while(!q.empty()) {
            int x = q.front().first.first, y = q.front().first.second;
            int minDistance = q.front().second;
            q.pop();
            ans[x][y] = minDistance;

            loop(k, 4) {
                int nx = x + dx[k], ny = y + dy[k];
                if(nx >= 0 && nx < n && ny >= 0 && ny < m && visited[nx][ny] == 0) {
                    visited[nx][ny] = 1;
                    q.push(make_pair(make_pair(nx, ny), minDistance + 1));
                }
            }
        }
        return ans;
    }
};
```
</details>

<details>
<summary>GFG</summary>

```
#define loop(i, n) for(int i = 0; i < n; i++)

class Solution {
  public:
    // Function to find distance of nearest 1 in the grid for each cell.
    vector<vector<int>> nearest(vector<vector<int>>& grid) {
        // Code here
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> ans(n, vector<int> (m));
        
        loop(i, n) {
            loop(j, m) {
                if(grid[i][j] == 1) {
                    ans[i][j] = 0;
                } else {
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    
                    while(!q.empty()) {
                        int x = q.front().first, y = q.front().second;
                        q.pop();
                        bool chk = 0;
                        loop(k, 4) {
                            int nx = x + dx[k], ny = y + dy[k];
                            
                            if(nx >= 0 && nx < n && ny >= 0 && ny < m) {
                                if(grid[nx][ny] == 1) {
                                    ans[i][j] = abs(i - nx) + abs(j - ny);
                                    chk = 1;
                                    break;
                                } else {
                                    q.push({nx, ny});
                                }
                            }
                        }
                        if(chk)
                            break;
                    }
                }
            }
        }
        return ans;
    }
};
```

</details>