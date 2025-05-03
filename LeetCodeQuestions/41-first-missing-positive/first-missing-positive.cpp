class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_map<int, int> mp;

        for (auto x: nums) {
            mp[x]++;
        }

        int ans = 1;

        while (mp.find(ans) != mp.end()) {
            ans++;
        }

        return ans;
    }
};