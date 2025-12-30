class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int ans = 0;
        int i = 0, j = 0;

        auto check = [&](int x, int y) -> bool {
            set<int> uq;
            set<int> dist;

            // check all the rows
            for (int i = x; i <= x + 2; i++) {
                int sum = 0;
                for (int j = y; j <= y + 2; j++) {
                    if (grid[i][j] > 9 || grid[i][j] < 1) 
                        return false;
                    dist.insert(grid[i][j]);
                    sum += grid[i][j];
                }
                uq.insert(sum);
            }      

            if (dist.size() != 9) return false;
            if (uq.size() != 1) 
                return false;
            
            // check all the columns
            for (int j = y; j <= y + 2; j++) {
                int sum = 0;
                for (int i = x; i <= x + 2; i++) {

                    sum += grid[i][j];
                }
                uq.insert(sum);
            }

            if (uq.size() != 1) return false;

            // check two diagonals
            int i = x, j = y;
            int sum = 0;
            while (i <= x + 2 && j <= y + 2) {
                sum += grid[i][j];
                i++, j++;
            }
                cout << sum << "\n";

            uq.insert(sum);
            if (uq.size() != 1) return false;

            i = x, j = y + 2;
            sum = 0;
            while (i <= x + 2 && j >= y) {
                // cout << grid[i][j] << " ";
                sum += grid[i++][j--];
            }
       
            uq.insert(sum);
            return uq.size() == 1;
        };


        while (i + 2 < n) {
            j = 0;
            while (j + 2 < m) {
                cout << i << " " << j << "\n";
                ans += check(i, j);
                j++;
            }
            i++;
        }

        return ans;
    }
};