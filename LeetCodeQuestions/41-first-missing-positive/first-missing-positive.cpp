class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int ans = 1;

        for (auto x: nums) {
            if (x < 0) {
                continue;
            }
            if (ans == x) {
                ans++;
            }
            else if (x > ans) {
                return ans;
            }
        }
        return ans;
    }
};