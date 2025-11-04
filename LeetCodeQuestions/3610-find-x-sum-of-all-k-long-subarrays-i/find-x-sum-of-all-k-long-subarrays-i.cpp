class Solution {
public:
    vector<int> findXSum(vector<int>& a, int k, int x) {
        int n = a.size();
        map<int, int> mp;
        for (int i = 0; i < k; i++) {
            mp[a[i]]++;
        }      
        auto computeXSum = [&]() -> int {
            vector<pair<int, int>> vp;
            for (auto it: mp) {
                vp.push_back({it.second, it.first});
            }
            sort(vp.begin(), vp.end(), [&](const pair<int, int>& p1, const pair<int, int> &p2) {
                if (p1.first != p2.first) {
                    return p1.first > p2.first;
                }
                return p1.second > p2.second;
            });
            int sum = 0;
            for (int i = 0; i < min(x, (int) vp.size()); i++) {
                auto it = vp[i];
                sum += it.first * it.second;
            } 
            return sum;
        };

        vector<int> ans;
        ans.push_back(computeXSum());
        for (int i = 0, j = k; j < n; j++, i++) {
            mp[a[i]]--, mp[a[j]]++;
            if (mp[a[i]] == 0) {
                mp.erase(a[i]);
            }
            ans.push_back(computeXSum());
        }
        return ans;
    }
};