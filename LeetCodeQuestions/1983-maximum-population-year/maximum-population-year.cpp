class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<pair<int, int>> vp;
        for (auto a : logs) {
            vp.push_back({a[0], 1});
            vp.push_back({a[1], 0});
        }

        sort(vp.begin(), vp.end());

        int ans = 0;
        int curr = 0;
        for (auto x : vp) {
            if (x.second == 1) {
                curr++;
                ans = max(ans, curr);
            }
            else {
                curr--;
            }
        }
        for (auto x : vp) {
            if (x.second == 1) {
                curr++;
                if (curr == ans) {
                    return x.first;
                }
            }
            else {
                curr--;
            }
        }

        return ans;
    }
};