class Solution {
public:
    vector<vector<int>> allSubsets;

    void genSubsets(vector<int> &nums, vector<int> &a, int index = 0) {
        if (index >= nums.size()) {
            allSubsets.push_back(a);
            return;
        }

        genSubsets(nums, a, index + 1);
        a.push_back(nums[index]);
        genSubsets(nums, a, index + 1);
        a.pop_back();
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        genSubsets(nums, temp);
        return allSubsets;
    }
};