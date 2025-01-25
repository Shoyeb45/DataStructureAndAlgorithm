class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int low = 1, high = n - 1;
        int ans = -1;

        std::function<bool(int)> check = [&](int mid) {
            int num_smaller = 0;
            for (auto x : nums) {
                num_smaller += (x <= mid);
            }

            // By piegon hole principle
            return num_smaller > mid;
        };

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (check(mid)) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return ans;
    }
};