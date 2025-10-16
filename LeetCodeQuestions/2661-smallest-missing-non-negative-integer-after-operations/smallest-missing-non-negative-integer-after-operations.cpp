class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        map<int, int> mp;

        for (auto &x: nums) {
            int remainder = (x % value + value) % value;
            if (mp.find(remainder) != mp.end()) {
                x = value + mp[remainder];
            } else {
                x = remainder;
            }
            mp[remainder] = x;
        }
        sort(nums.begin(), nums.end());
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == ans) {
                ans++;
            } else {
                break;
            }
        }

        return ans;
    }
};