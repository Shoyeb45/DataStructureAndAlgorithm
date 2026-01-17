class Solution {
public:

    long long largestSquareArea(vector<vector<int>>& bl, vector<vector<int>>& tr) {
        int n = bl.size();

        int len = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int x1 = bl[i][0], y1 = bl[i][1];
                int x2 = tr[i][0], y2 = tr[i][1];
                int a1 = bl[j][0], b1 = bl[j][1];
                int a2 = tr[j][0], b2 = tr[j][1];

                int x5 = max(x1, a1);
                int y5 = max(y1, b1);
                int x6 = min(x2, a2);
                int y6 = min(y2, b2);

                if (x5 <= x6 && y5 <= y6) 
                    len = max(len, min(x6 - x5, y6 - y5));
            }
        }

        long long ans = (long long) len * len;
        return ans;
    }
};