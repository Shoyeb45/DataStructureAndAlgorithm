class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        vector<int> ans;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (i + 1 < n && nums[i] < nums[i + 1]) {
                int j = i;
                while (j + 1 < n && nums[j] < nums[j + 1]) {
                    j++;
                }
                ans.push_back(j - i + 1);
                i = j;
            } else {
                ans.push_back(1);
            }
        }   
        for (auto x: ans) {
            cout << x << " ";
        }
        cout << "\n";
        for (int i = 0; i < ans.size(); i++) {
            if (ans[i] >= 2 * k) {
                return true;
            }
            if (i + 1 < ans.size() && ans[i] >= k && ans[i + 1] >= k) {
                return true;
            }
        }
        return false;
    }
};