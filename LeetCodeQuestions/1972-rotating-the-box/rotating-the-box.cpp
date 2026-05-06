class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& a) {
        int n = a.size(), m = a[0].size();

        for (auto &row: a) {
            for (int i = m - 1; i >= 0; i--) {
                if (row[i] == '.') {
                    vector<int> idxs;
                    for (int j = i - 1; j >= 0; j--) {
                        if (row[j] == '*') break;
                        if (row[j] == '#') idxs.push_back(j);
                    }
                    int j = i;
                    for (auto idx: idxs) {
                        row[j--] = '#';
                        row[idx] = '.';
                    }
                }
            }
        }

        vector<vector<char>> ans(m, vector<char>(n));

      
        for (int j = 0; j < m; j++) {
            for (int i = n - 1; i >= 0; i--) {
                ans[j][n - i - 1] = a[i][j];
            }
        }
        return ans;
    }
};