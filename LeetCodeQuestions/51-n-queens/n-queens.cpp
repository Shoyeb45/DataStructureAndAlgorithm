class Solution {
public:

    bool valid(vector<pair<int, int>> &indices, int rowIndex, int columnIndex) {
        for (auto index : indices) {
            if (
                rowIndex == index.first ||
                columnIndex == index.second || 
                abs(rowIndex - index.first) == abs(columnIndex - index.second)
            ) {
                return false;
            }
        }
        return true;
    }

    void f(int n, int rowIndex, vector<vector<string>> &ans, string temp, vector<pair<int, int>> &indices, vector<string> &tempString) {
        // Found solution
        if (rowIndex >= n) {
            ans.push_back(tempString);
            return;
        }


        for (int i = 0; i < n; i++) {
            if (valid(indices, rowIndex, i)) {
                // Make changes
                temp[i] = 'Q';
                indices.push_back(make_pair(rowIndex, i));
                tempString.push_back(temp);

                f(n, rowIndex + 1, ans, string(n , '.'), indices, tempString);

                // undo
                temp[i] = '.';
                indices.pop_back();
                tempString.pop_back();
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        string temp(n, '.');
        vector<string> tempString;
        vector<pair<int, int>> indices;
        f(n, 0, ans, temp, indices, tempString);
        return ans;
    }
};