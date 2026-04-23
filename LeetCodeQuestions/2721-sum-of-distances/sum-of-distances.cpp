using ll = long long;

class Solution {
public:
    vector<long long> distance(vector<int>& nums) {

        unordered_map<int, vector<int>> mp;

        int n = nums.size();
        vector<ll> ans(n);

        for (int i = 0; i < n; i++) 
            mp[nums[i]].push_back(i);      
        
        for (auto &x: mp) {
            if (x.second.size() == 1) continue;
            auto &arr = x.second;
            vector<ll> suff(arr.size());
            suff[arr.size() - 1] = arr.back();

            for (int i = (int) arr.size() - 2; i >= 0; i--) {
                suff[i] = suff[i + 1] + arr[i];
            }
            ll pref = 0;

            int m = arr.size();
            for (int i = 0; i < arr.size(); i++) {
                ans[arr[i]] = 0;
                if (i + 1 < arr.size()) {
                    int count = m - i - 1;
                    ll sum = (ll) count * arr[i];
                    ans[arr[i]] += (suff[i + 1] - sum) + ((ll) i * arr[i] - pref);
                } else {
                    ans[arr[i]] += ((ll) i * arr[i] - pref);
                }
                pref += arr[i];
            }
            // 0 3 5 8
            // i j k l m n
            // 1 2 3
        }
        return ans;
    }
};