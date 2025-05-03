class Solution {
public:

    void nextPermutation(vector<int>& nums) {
        if (is_sorted(nums.rbegin(), nums.rend())) {
            reverse(nums.begin(), nums.end());
            return;
        } 

        int n = nums.size();

        for (int i = n - 1; i >= 1; i--) {
            if (nums[i - 1] < nums[i]) {
                // find next greater element of nums[i - 1]
                int nge = i;
                for (int j = i; j < n; j++) {
                    if (nums[j] <= nums[i - 1]) {
                        break;
                    }
                    else {
                        nge = j;
                    }
                }  

                // swap elements 
                swap(nums[i - 1], nums[nge]);

                // reverse elememts
                reverse(nums.begin() + i, nums.end());
                break;

            }
        }
    }   
};