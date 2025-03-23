class Solution {
public:
    int f(int idx, vector<int> &a, int target, int sum) {
        if (idx == a.size()) {
            return sum == target;
        }

  
        int ans = f(idx + 1, a, target, sum - a[idx]) + f(idx + 1, a, target, sum + a[idx]);

        return ans;
    }
    int findTargetSumWays(vector<int>& nums, int target) {

        return f(0, nums, target, 0);
    }
};