class Solution {
public:
    int digit_sum(int x) {
        int sum = 0;

        while (x) {
            sum += x % 10;
            x /= 10;
        }
        return sum;
    }
    int minElement(vector<int>& nums) {
        int ans = INT_MAX;

        for (auto x: nums) {
            ans = min(ans, digit_sum(x));
        }
        return ans;
    }
};