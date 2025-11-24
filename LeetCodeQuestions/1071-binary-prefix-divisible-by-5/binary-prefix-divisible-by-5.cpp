class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int n = nums.size();
        vector<bool> ans(n);
        int pw = 1;
        int num = 0;

        for (int i = 0; i < n; i++) {
            // pw = (pw * 2);
            num = (2 * num + nums[i]) % 5;
            ans[i] = num == 0; 
            // pw %= 5;
        }     
        return ans;
    }
};