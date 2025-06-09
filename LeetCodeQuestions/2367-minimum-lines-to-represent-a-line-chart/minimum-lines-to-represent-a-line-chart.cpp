class Solution {
public:
    int minimumLines(vector<vector<int>>& sp) {
        sort(sp.begin(), sp.end());

        int n = sp.size();
        int ans = 1;
        for (int i = 0; i < n - 2; i++) {
            int x1 = sp[i][0], x2 = sp[i + 1][0], x3 = sp[i + 2][0];
            int y1 = sp[i][1], y2 = sp[i + 1][1], y3 = sp[i + 2][1];
            // cout << x1 << " " << x2 << " " << x3 << "\n";
            // cout << y1 << " " << y2 << " " << y3 << "\n\n";
            long long d1 = 1LL * (y2 - y1) * (x3 - x2);
            long long d2 = 1LL * (y3 - y2) * (x2 - x1);
            if (d1 != d2) {
                   cout << x1 << " " << x2 << " " << x3 << "\n";
            cout << y1 << " " << y2 << " " << y3 << "\n\n";
                ans++;
            }
        }
        return (n == 1? 0:ans);
    }
};