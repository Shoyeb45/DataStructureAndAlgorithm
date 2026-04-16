class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        map<int, vector<int>> mp;

        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]].push_back(i);
        }

        vector<int> ans;
        int n = nums.size();
        for (auto q: queries) {
            auto &st = mp[nums[q]];
            if (st.size() == 1) {
                ans.push_back(-1);
                continue;
            }

            int ele_idx = 0;
            int low = 0, high = st.size() - 1;

            while (low <= high) {
                int mid = (low + high) / 2;
                if (st[mid] == q) {
                    ele_idx = mid;
                    break;
                } else if (st[mid] > q) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }

            // 1  2 3 4 5

            int left = st[(ele_idx - 1 + st.size()) % st.size()];
            int right = st[(ele_idx + 1) % st.size()];
            int d1 = abs(q - left);
            int d2 = abs(q - right);
            int _ans = min(min(d1, n - d1), min(d2, n - d2));
            ans.push_back(_ans);

        }

        return ans;
    }
};