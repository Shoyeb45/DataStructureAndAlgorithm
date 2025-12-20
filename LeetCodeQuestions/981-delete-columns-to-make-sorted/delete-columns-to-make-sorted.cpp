class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();

        int ans = 0;
        for (int i = 0; i < m; i++) {
            bool ok = false;
            char ch = strs[0][i];
            for (int j = 1; j < n; j++) {
                if (strs[j][i] < ch) {
                    ok = true;
                    break;
                }
                ch = strs[j][i];
            }
            ans += ok;
        }
        return ans;
    }
};