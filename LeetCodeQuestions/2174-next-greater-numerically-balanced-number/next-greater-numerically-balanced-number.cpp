class Solution {
public:
    bool is_balanced(int x) {
        int freq[10];
        fill(freq, freq + 10, 0);
        while (x) {
            int di = x % 10;
            x /= 10;
            freq[di]++;
        }
        for (int i = 0; i < 10; i++) {
            if (freq[i] == 0) {
                continue;
            }
            if (freq[i] != i) {
                return false;
            }
        }
        return true;
    }
    int nextBeautifulNumber(int n) {
        for (int i = n + 1; ; i++) {
            if (is_balanced(i)) {
                return i;
            }
        }
        return 1;
    }
};