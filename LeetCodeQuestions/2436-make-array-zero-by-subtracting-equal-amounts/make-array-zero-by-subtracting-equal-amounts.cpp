class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        vector<int> a;
        int mn = INT_MAX;
        for (auto x : nums) {
            if (x != 0) {
                mn = min(x, mn);
                a.push_back(x);
            }
        }

        int ans = 0;
        while (!a.empty()) {
            vector<int> temp;
            int temp_min = INT_MAX;
            for (auto x: a) {
                x -= mn;
                if (x != 0) {
                    temp_min = min(temp_min, x);
                    temp.push_back(x);
                }
            }
            a = temp;
            mn = temp_min;
            ans++;
        }

        return ans;
    }
};