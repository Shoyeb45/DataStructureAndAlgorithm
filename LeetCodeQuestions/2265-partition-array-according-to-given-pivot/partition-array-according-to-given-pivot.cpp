class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int less_than = 0;
        int greater_than = 0;
        int equal = 0;

        for (auto &x: nums) {
            if (x < pivot) {
                less_than++;
            } else if (x > pivot) {
                greater_than++;
            } else {
                equal++;
            }
        }

        int i = 0, j = less_than, k = less_than + equal;

        vector<int> a(nums.size());

        for (auto &x: nums) {
            if (x < pivot) {
                a[i++] = x;
            } else if (x > pivot) {
                a[k++] = x;
            } else {
                a[j++] = x;
            }
        }
        return a;
    }
};