class Solution {
public:
    int candy(vector<int>& a) {
        int ans = 0;
        int n = a.size();
        vector<int> choco(n, 0);

        for (int i = 0; i < n; i++) {
            if (i > 0 && a[i] > a[i - 1]) {
                choco[i] = choco[i - 1] + 1;
            } else {
                choco[i] = 1;
            }
        }

        for (int i = n - 1; i >= 0; i--) {
            if (i + 1 < n && a[i] > a[i + 1]) {
                if (choco[i] <= choco[i + 1]) {
                    choco[i] = choco[i + 1] + 1;
                } 
            } 
        }

        for (int x: choco) {
            cout << x << "\n";
            ans += x;
        }
        return ans;
    }
};