class Solution {
public:
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};

    bool f(int i, int j, vector<vector<char>> &mat, string &word, int idx) {
        int n = mat.size(), m = mat[0].size();
        if (idx >= word.size()) {
            return true;
        }
        if (i < 0 || j < 0 || i >= n || j >= m) {
            return false;
        }

        bool ans = false;
        for (int k = 0; k < 4; k++) {
            int nx = dx[k] + i, ny = dy[k] + j;

            if (nx >= 0 && ny >= 0 && nx < n && ny < m && mat[nx][ny] != '$') {
                if (word[idx] == mat[nx][ny]) {
                    char ch = mat[nx][ny];
                    mat[nx][ny] = '$';
                    ans |= f(nx, ny, mat, word, idx + 1);
                    mat[nx][ny] = ch;
                }
            }
        
        }
        return ans;
    }
    bool exist(vector<vector<char>>& board, string word) {
        bool ans = false;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == word[0]) {
                    char ch = board[i][j];
                    board[i][j] = '$';
                    if (f(i, j, board, word, 1)) {
                        return true;
                    }
                    board[i][j] = '$';
                    board[i][j] = ch;
                }
            }
        }
        return false;   
    }
};