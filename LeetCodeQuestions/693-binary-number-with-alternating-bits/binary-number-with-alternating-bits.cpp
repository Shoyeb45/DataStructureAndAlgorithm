class Solution {
public:
    bool hasAlternatingBits(int n) {
        int bit = (bool) (n & 1);
        int k = (int) log2(n) + 1;

        for (int i = 1; i < k; i++) {
            bool x = ((1 << i) & n);
            if (bit == x) return false;
            bit = x;
        }
        return true;
    }
};