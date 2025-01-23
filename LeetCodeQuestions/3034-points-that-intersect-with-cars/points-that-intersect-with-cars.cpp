class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        vector<int> freq(102, 0);

        for (auto x : nums) {
            freq[x[0]] += 1;
            freq[x[1] + 1] -= 1;
        }

        int sum = 0, ans = 0;

        for (auto x: freq) {
            sum += x;
            if (sum != 0) {
                ans++;
            }
        }

        return ans;
    }
};