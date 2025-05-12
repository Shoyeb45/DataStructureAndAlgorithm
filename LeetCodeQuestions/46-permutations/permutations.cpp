class Solution {
public:
    void findAllPermutation(vector<int> nums, vector<int> &ans, vector<vector<int>> &allPermutation) {
        if (nums.empty()) {
            allPermutation.push_back(ans);
            return;
        }

        for (auto x: nums) {
            ans.push_back(x);
            vector<int> new_vec;
            for (auto y: nums) {
                if (x != y) {
                    new_vec.push_back(y);
                }
            }
            findAllPermutation(new_vec, ans, allPermutation);
            ans.pop_back();
        }
        
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        findAllPermutation(nums, temp, ans);
        return ans;
    }
};