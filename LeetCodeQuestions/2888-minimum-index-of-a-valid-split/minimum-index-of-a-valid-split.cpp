class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int num = 0, cnt = 0;
        int n = nums.size();
        for (auto x: nums) {
            if (cnt == 0) {
                num = x;
            }
            cnt += (num == x? 1: -1);
        }

        cnt = 0;
        for (auto x: nums) {
            cnt += (x == num);
        }

        if (cnt <= nums.size() / 2) {
            return -1;
        }

        vector<int> prefix(nums.size(), 0), suffix(nums.size(), 0);
        prefix[0] = (nums[0] == num); 
        suffix[n - 1] = (nums[n - 1] == num);

        for (int i = 1; i < n; i++) {
            prefix[i] += (nums[i] == num) + prefix[i - 1];
        }

        for (int i = n - 2; i >= 0; i--) {
            suffix[i] += (nums[i] == num) + suffix[i + 1];

        }

        for (int i = 0; i < n; i++) {
            int leftCount = prefix[i], rightCount = (i == n - 1? 0: suffix[i + 1]);
            
            if (i == 4) {
                cout << leftCount << " " << rightCount << "\n";
            }
            
            if (leftCount > (i + 1) / 2 && rightCount > (n - i - 1) / 2) {
                return i;
            }
        }

        return -1;
    }
};