class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();

        unordered_map<int, pair<int, int>> mp;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                mp[mat[i][j]] = make_pair(i, j);
            }
        }
        vector<int> row(n, 0), col(m, 0);

        for (int x = 0; x < arr.size(); x++) {
            int idx = arr[x];
            int i = mp[idx].first, j = mp[idx].second;
            row[i]++, col[j]++;
            if (row[i] == m || col[j] == n) {
                return x;
            }  
        }
        
        return -1;
    }
};