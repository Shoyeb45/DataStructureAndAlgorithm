class Solution {
public:
    void f(int i, vector<int> &nums, vector<int> &a, vector<vector<int>> &ans) {
        if (i >= nums.size()) {
            ans.push_back(a);
            return;
        }

        int cnt = 0;
        int ele = nums[i];
        while (i < nums.size() && nums[i] == ele) {
            i++, cnt++;
        } 

        // Take zero times
        f(i, nums, a, ans);

        for (int j = 0; j < cnt; j++) {
            a.push_back(ele);
            f(i, nums, a, ans);
        }

        // remove all the elements
        for (int i = 0; i < cnt; i++) {
            a.pop_back();
        }

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> a;
        f(0, nums, a, ans);
        return ans;        
    }
};