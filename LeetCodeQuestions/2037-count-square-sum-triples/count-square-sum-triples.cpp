class Solution {
public:
    bool is_square(int c) {
        int x = (int) sqrt(c);
        // cout << c << " " << x << "\n";
        return x * x == c;
    }

    int countTriples(int n) {
        int ans = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                // c_2 = i^2 + j^2
                int c = i * i + j * j;
                if (!is_square(c)) {
                    continue;
                }

                int _sqrt = (int) sqrt(c);
                if (_sqrt <= n) {
                    // cout << i << ' ' << j << ' ' << _sqrt << "\n";
                    ans++;
                    ans += (i != j);
                }
            }
        }
        
        return ans;
    }
};