class Solution {
public:
    int minimumOneBitOperations(int n, int idx = 31) {
        int ans = 0;
        if (idx < 0) {
            return 0;
        }

        int bit = ((1 << idx) & n);
        if (bit) {
            return ((1 << (idx + 1)) - 1) - minimumOneBitOperations(n, idx - 1);
        }
        return minimumOneBitOperations(n, idx - 1);   
    }
};