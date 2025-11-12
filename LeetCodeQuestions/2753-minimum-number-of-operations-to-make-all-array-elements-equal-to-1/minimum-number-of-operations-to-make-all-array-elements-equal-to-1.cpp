class Solution {
public:
    int minOperations(vector<int>& a) {
        int n = a.size();
        int len = INT_MAX;
        int l = 0, r = 0;
        int cnt1 = 0;
        for (int i = 0; i < n; i++) {
            cnt1 += a[i] == 1;
        }
        if (cnt1) {
            return n - cnt1;
        }

        for (int i = 0; i < n; i++) {
            int g = 0;
            for (int j = i; j < n; j++) {
                g = __gcd(g, a[j]);
                if (g == 1) {
                    int temp = j - i + 1;
                    if (temp < len) {
                        len = temp;
                        l = i, r = j;
                    }
                }
            }
        }

        if (len == INT_MAX) {
            return -1;
        }
        cout << len << " " << l << " " << r << "\n"; 
        return r - l + n - 1;
    }
};