class Solution {
public:
    bool valid(vector<pair<int, int>> &indices, int row, int col) {
        for (auto x : indices) {
            if (x.second == col || abs(x.first - row) == abs(x.second - col)) {
                return false;
            }
        }
        return true;
    }

    int numberOfPuzzle(vector<pair<int, int>> &indices, int rowIndex, int n) {
        if (rowIndex >= n) {
            return 1;
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (valid(indices, rowIndex, i)) {
                indices.push_back({rowIndex, i});
                ans += numberOfPuzzle(indices, rowIndex + 1, n);
                indices.pop_back();
            }
        }
        return ans;
    }
    int totalNQueens(int n) {
        vector<pair<int, int>> ind; 
        return numberOfPuzzle(ind, 0, n);
    }
};