class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        map<int, vector<int>> mp;

        int n = nums.size();
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        auto reverse = [&](int x) -> int {
            int ans = 0;
            while (x) {
                int last = x % 10;
                ans = ans * 10 + last;
                x /= 10;
            }
            return ans;
        };

        int ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            int rev = reverse(nums[i]);
            // 6
            // 0 1 5 7
            // first element: x > 6
            auto &st = mp[rev];
            // 33 -> 3 4
            // if (st.size() == 1) continue;

            auto it = lower_bound(st.begin(), st.end(), i);
            if (it != st.end()) {
                int idx = it - st.begin();
                if (idx - 1 >= 0) {
                    ans = min(ans, (int) abs(st[idx - 1] - i));
                }

                if (st[idx] == i) idx++;
                if (idx < st.size())
                    ans = min(ans, (int) abs(st[idx] - i));
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};