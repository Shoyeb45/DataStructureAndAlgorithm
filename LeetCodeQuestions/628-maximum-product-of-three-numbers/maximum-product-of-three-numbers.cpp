#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:

    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        int mn1 = nums[0], mn2 = nums[1];
        int mx1 = nums[n - 1], mx2 = nums[n - 2], mx3 = nums[n - 3];

        return max(mn1 * mn2 * mx1, mx1 * mx2 * mx3);
    }
};
