class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n - 1, mid;
        int idx = n;
        while (low <= high) {
            mid = (low + high) / 2;

            if (nums[mid] == target) {
                return mid;
            }
            else if (nums[mid] > target) {
                high = mid - 1;
                idx = mid;
            }
            else {
                low = mid + 1;
            }
        }

        return idx;
    }
};