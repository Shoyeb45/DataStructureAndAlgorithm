class Solution {
public:
    int countBattleships(vector<vector<char>>& a) {
        int ans = 0;
        int n = a.size(), m = a[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] == 'X') {
                    a[i][j] = '.';
                    int temp_i = i + 1, temp_j = j + 1;
                    while (temp_i < n && a[temp_i][j] == 'X') {
                        a[temp_i++][j] = '.';
                    }

                    while (temp_j < m && a[i][temp_j] == 'X') {
                        a[i][temp_j++] = '.';
                    }
                    ans++;
                } 
            }
        }

        return ans;
    }
};

// . X X
// X . .
// . . X
