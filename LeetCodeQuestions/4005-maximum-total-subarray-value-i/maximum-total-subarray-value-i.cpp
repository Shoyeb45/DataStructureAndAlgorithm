class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int val = *max_element(nums.begin(), nums.end()) - *min_element(nums.begin(), nums.end());

        return (long long) val * k;
    }
};