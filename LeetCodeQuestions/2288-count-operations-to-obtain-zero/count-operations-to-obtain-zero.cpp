class Solution {
public:
    int countOperations(int x, int y) {
        int ans = 0;
        if (x < y) {
            swap(x, y);
        }
        while (x && y) {
            int k = x / y;
            x -= max(k * y, 0);
            if (x < y) {
                swap(x, y);
            }
            ans += k;
        }
        return ans;
    }
};