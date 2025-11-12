class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int prev = 0;
        for (int i = 0; i < n; i++) {
            int len;
            if (i + 1 < n && nums[i] < nums[i + 1]) {
                int j = i;
                while (j + 1 < n && nums[j] < nums[j + 1]) {
                    j++;
                }
                len = j - i + 1;
                i = j;
            } else {
                len = 1;
            }
            if (len >= 2 * k || (len >= k && prev >= k)) {
                return true;
            }
            prev = len;
        }   
        
        return false;
    }
};