class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        swap(n, m);

        // 1 -> Guard, 2 -> Wall
        vector<vector<char>> mat(n, vector<char>(m, '0'));
        for (auto g: guards) {
            mat[g[0]][g[1]] = '1';
        }
        for (auto w: walls) {
            mat[w[0]][w[1]] = '2';
        }
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};


        for (auto& g: guards) {
            int x = g[0], y = g[1];
            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k], ny = y + dy[k];
                while (nx >= 0 && ny >=0 && nx < n && ny < m && mat[nx][ny] != '2' && mat[nx][ny] != '1' && mat[nx][ny] != '2') {
                    mat[nx][ny] = '3';
                    nx += dx[k], ny += dy[k];
                }
            }
        }

    
        int ans = 0;
        for (auto &x: mat) {
            ans += count(x.begin(), x.end(), '0');
        }
        return ans;
    }
};