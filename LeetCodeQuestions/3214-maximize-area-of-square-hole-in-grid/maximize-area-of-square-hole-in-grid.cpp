class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& h, vector<int>& v) {
        sort(h.begin(), h.end());
        sort(v.begin(), v.end());

        int hx = h[0], hy = h[0];
        int mx = 1;

        for (int i = 1; i < h.size(); i++) {
            if (h[i - 1] + 1 == h[i]) {
                int j = i;
                while (j < h.size() && h[j - 1] + 1 == h[j]) {
                    j++;
                }
                int len = j - i + 1;
                if (len > mx) {
                    mx = len;
                    hx = h[i - 1], hy = h[j - 1];
                }
                i = j - 1;
            }
        }
        mx = 1;
        int vx = v[0], vy = v[0];
        for (int i = 1; i < v.size(); i++) {
            if (v[i - 1] + 1 == v[i]) {
                int j = i;
                while (j < v.size() && v[j - 1] + 1 == v[j]) {
                    j++;
                }

                int len = j - i + 1;
                // cout << i << " " << j << "\n";

                if (len > mx) {
                    mx = len;
                    vx = v[i - 1], vy = v[j - 1];
                }
                i = j - 1;
            }
        }

        // cout << vx << " " << vy << "\n";
        int l = min(vy - vx + 2, hy - hx + 2);

        return l * l;
    }
};