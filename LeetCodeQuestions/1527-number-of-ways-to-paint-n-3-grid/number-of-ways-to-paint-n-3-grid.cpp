
class Solution {
public:
    // 0, 1, 2
    int n;
    int dp[5000][3][3][3];
    const int mod = int(1e9) + 7;

    int fn(int row, int id1, int id2, int id3) {
        // cout 
        if (row == n) {
            return 1;
        }   
        if (id1 != -1 && dp[row][id1][id2][id3] != -1) {
            return dp[row][id1][id2][id3];
        }

        int ans = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    if (i == j || j == k) continue;
                    if (id1 != i && id2 != j && id3 != k) {
                        // cout << i << " " << j << " " << k << "\n";
                        ans = (ans + fn(row + 1, i, j, k)) % mod;

                    }
                }
            }
        }

        return id1 != -1 ? dp[row][id1][id2][id3] = ans: ans;
    }
    int numOfWays(int n) {
        memset(dp, -1, sizeof dp);
        this->n = n;
        return fn(0, -1, -1, -1);
    }
};