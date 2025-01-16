class Solution {
public:
    int xorOfAll(vector<int> &nums) {
        int ans = 0;
        for (int x : nums) {
            ans ^= x;
        }
        return ans;
    }

    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0;
        if (((int)nums1.size() & 1) == 1) {
            ans ^= xorOfAll(nums2);
        }

        if (((int)nums2.size() & 1) == 1) {
            ans ^= xorOfAll(nums1);
        }
        return ans;
    }
};