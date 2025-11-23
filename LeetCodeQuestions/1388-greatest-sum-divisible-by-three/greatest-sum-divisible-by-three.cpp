class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int ans = 0;
        sort(nums.begin(), nums.end());
        for (auto x: nums) {
            ans += x;
        }
        if (ans % 3 == 0) {
            return ans;
        }
        int rem = ans % 3;
        int temp1 = 0, temp2 = 0;
        for (auto x: nums) {
            if (rem == x % 3) {
                temp1 += x;
                break;
            }
        }
        int taken = 0;
        for (auto x: nums) {
            if (taken == 2) break;
            if (3 - rem == x % 3) {
                temp2 += x;
                taken++;
            }
        }
        cout << temp1 << " " << temp2 << "\n";
        if (temp1 == 0) temp1 = INT_MAX;
        if (temp2 == 0 || taken != 2) temp2 = INT_MAX;
        cout << ans << "\n";
        return ans - min(temp2, temp1);
    }
};