class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ans = 0;
        for (auto x: nums) {
            if (x % 3 == 0) continue;
            int y1 = x - (x % 3), y2 = x + 3 - (x % 3);

            cout << x << " " << y1 << " " << y2 << '\n';
            int temp = 0;
            if (y1 % 3 == 0) {
                temp = abs(y1 - x);
            }
            if (y2 % 3 == 0) {
                temp = min(temp, abs(y2 - x));
            }
            ans += temp;
        }
        return ans;
    }
};