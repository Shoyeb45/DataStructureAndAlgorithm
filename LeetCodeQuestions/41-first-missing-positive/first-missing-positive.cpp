class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            
            while (nums[i] != i + 1 && (nums[i] >= 1 && nums[i] < n + 1)) {
                if (nums[i] == nums[nums[i] -1 ]) {
                    break;
                }
                swap(nums[i], nums[nums[i] - 1]);
            }
        }

        
        int ans = 1;
        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }

        return n + 1;
    }
};