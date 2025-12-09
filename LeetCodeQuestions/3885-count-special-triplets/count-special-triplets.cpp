const int mod = (int) 1e9 + 7;

class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        int n = nums.size();
        // for each i, if I can calculate how many elements are there
        // on left and right side with value 2 * a[i], then my work is done.
        map<int, int> ms_l, ms_r;

        for (int i = 1; i < n; i++)
            ms_r[nums[i]]++;

        ms_l[nums[0]]++;
        
        long long ans = 0;
        for (int i = 1; i < n; i++) {
            int x = 2 * nums[i];
            ms_r[nums[i]]--;

            int left = ms_l[x];
            int right = ms_r[x];

            ans = (ans + (long long) left * right) % mod;
            ms_l[nums[i]]++;
        }

        return (int) ans;
    }
};