class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> cnts(n);

        auto cnt_from_end = [&](vector<int> &a) -> int {
            int n = a.size();
            int cnt = 0;
            for (int i = n - 1; i >= 0; i--) {
                if (a[i]) break;
                cnt++;
            }
            return cnt;
        };

        for (int i = 0; i < n; i++) {
            cnts[i] = cnt_from_end(grid[i]);
        }

        for (int i = 0; i < n; i++) 
            cout << cnts[i] << " ";
            cout << "\n";
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (cnts[i] >= n - i - 1) continue;
            for (int j = i + 1; j < n; j++) {
                if (cnts[j] >= n - i - 1) {
                    ans += j - i;
                    // swap(cnts[j], cnts[i]);
                    int tmp = cnts[j];
                    for (int k = j; k > i; k--) 
                        cnts[k] = cnts[k - 1];
                    cnts[i] = tmp;
                    break;
                }
            }
        }


        for (int i = 0; i < n; i++) {
            if (cnts[i] < n - i - 1) return -1;
            cout << cnts[i] << " ";
        }

        return ans;
    }
};