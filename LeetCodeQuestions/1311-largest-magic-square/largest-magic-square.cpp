using ll = long long;
class Solution {
public:

    int largestMagicSquare(vector<vector<int>>& grid) {
        int ans = 1;
        int n = grid.size(), m = grid[0].size();

        auto is_magic_sq = [&](int i, int j, int x, int y) -> bool {
            set<ll> st;
            // rows
            for (int k = i; k <= x; k++) {
                ll sum = 0;
                for (int z = j; z <= y; z++) 
                    sum += grid[k][z];
                st.insert(sum);
            }
            if (st.size() != 1) return false;

            for (int z = j; z <= y; z++) {
                ll sum = 0;
                for (int k = i; k <= x; k++) 
                    sum += grid[k][z];
                st.insert(sum);
            }
            if (st.size() != 1) return false;

            int k = i, z = j;
            ll sum = 0;
            while (k <= x && z <= y) {
                sum += grid[k++][z++];
            }
            st.insert(sum);
            if (st.size() != 1) return false;

            sum = 0;
            k = i, z = y;
            while (k <= x && z >= j) {
                sum += grid[k++][z--];
            }
            st.insert(sum);
            if (st.size() != 1) return false;

            return true;
        }; 

        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
            for (int x = i + 1; x < n; x++) for (int y = j + 1; y < m; y++) {
                if (x - i == y - j && is_magic_sq(i, j, x, y)) {
                cout << i << " " << j << " " << x << ' ' << y << "\n";
                    ans = max(ans, x - i + 1);
                }
            }
        }   

        return ans;
    }
};