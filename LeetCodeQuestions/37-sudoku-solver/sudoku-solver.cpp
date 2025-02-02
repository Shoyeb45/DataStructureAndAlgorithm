class Solution {
public:
    set<int> cells[9], rows[9], cols[9];

    void print(vector<vector<char>> &a) {
        for (auto x : a) {
            for (auto y: x) {
                cout << y << " ";
            }
            cout << '\n';
        }
    }
    vector<vector<char>> ans;

    void solve(vector<vector<char>>& board, int rowIndex = 0, int colIndex = 0) {
        if (rowIndex >= 9) {
            ans = board;
            cout << endl;
            return;
        }

        if (colIndex >= 9) {
            solve(board, rowIndex + 1, 0);
            return;
        }

        if (board[rowIndex][colIndex] != '.') {
            solve(board, rowIndex, colIndex + 1);
            return;
        }

        for (int num = 1; num <= 9; num++) {
            if (rows[rowIndex].count(num) || cols[colIndex].count(num) || cells[(rowIndex / 3) * 3 + (colIndex / 3)].count(num)) {
                continue; 
            }
            
            // Do Changes
            cells[(rowIndex / 3) * 3 + (colIndex / 3)].insert(num);
            cols[colIndex].insert(num);
            rows[rowIndex].insert(num);
            
            // cout << num << "\n";
            board[rowIndex][colIndex] = num + '0';

            solve(board, rowIndex, colIndex + 1);
            // UndoChanges
            board[rowIndex][colIndex] = '.';   
            // cout << max(rowIndex / 3, j / 3) << "\n";
            cells[(rowIndex / 3) * 3 + (colIndex / 3)].erase(num);
            cols[colIndex].erase(num);
            rows[rowIndex].erase(num);

        
        }
        
    }
    void solveSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] != '.') {
                    int val = board[i][j] - '0';
                    rows[i].insert(val);
                    cols[j].insert(val);
                    cells[(i / 3) * 3 + (j / 3)].insert(val);
                }
            }
        }  
        solve(board);
        board = ans;
    }
};