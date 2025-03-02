class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> mat = image;    
        int n = mat.size(), m = mat[0].size();
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, 1, -1};

        
        queue<pair<int, int>> q; 
        q.push(make_pair(sr, sc));
        int startColor = mat[sr][sc];

        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            mat[x][y] = color;

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx >= 0 && ny >= 0 && nx < n && ny < m && mat[nx][ny] == startColor && mat[nx][ny] != color) {
                    q.push(make_pair(nx, ny));
                }
            }
        }

        return mat;
    }
};