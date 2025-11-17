class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        
        int prev = -1;
        
        for (int i = 0; i < (int) nums.size(); i++) {
            if (nums[i] == 1 && prev != -1 && i - prev - 1 < k) {
                return false;
            }
            if (nums[i] == 1) {
                prev = i;
            }
        }

        return true;
    }
};