class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        // nums[i] = (ans[i]) | (ans[i] + 1)
        // 11 = 10 | 11 
        // 101 = 100 | 101 
        // 11 | 100
        // 1 || 10
        int n = nums.size();
        vector<int> ans(n, -1);
        
        for (int i = 0; i < n; i++) {
            for (int j = 1; j <= nums[i]; j++) {
                if ((j | (j + 1)) == nums[i]) {
                    ans[i] = j;
                    break;
                }
            }
        }
        
        return ans;
    }
};