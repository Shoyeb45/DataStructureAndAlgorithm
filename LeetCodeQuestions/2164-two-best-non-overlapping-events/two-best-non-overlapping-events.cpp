class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        map<int, int> mp;

        for (auto& x: events) {
            mp[x[1]] = max(mp[x[1]], x[2]);
        }

        auto curr = next(mp.begin());
        auto _prev = mp.begin();

        for (; curr != mp.end(); _prev = curr, curr = next(curr)) {
            mp[curr->first] = max(mp[curr->first], mp[_prev->first]);
        }

        vector<int> a;
        for (auto x: mp) a.push_back(x.first);

        sort(events.begin(), events.end());

        int ans = 0;

        auto f = [&](int x) -> int {
            auto r = upper_bound(a.begin(), a.end(), x);

            if (r == a.begin()) {
                return 0;
            }
            return mp[*prev(r)];
        };

        for (auto& x: events) {
            int s = x[0], e = x[1];
            ans = max(ans, f(s - 1) + x[2]);
        }
        return ans;
    }
};