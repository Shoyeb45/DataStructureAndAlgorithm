class Solution {
public:
    int sum_n(int n) {
        return n * (n + 1) / 2;
    }

    int totalMoney(int n) {
        int ans = 0;
        int monday = 1;    
        while (n) {
            if (n >= 7) {
                ans += sum_n(monday + 6) - sum_n(monday - 1);
                n -= 7;
            } else {
                ans += sum_n(monday + n - 1) - sum_n(monday - 1);
                n = 0;
            }
            monday++;
        }
        return ans;
    }
};