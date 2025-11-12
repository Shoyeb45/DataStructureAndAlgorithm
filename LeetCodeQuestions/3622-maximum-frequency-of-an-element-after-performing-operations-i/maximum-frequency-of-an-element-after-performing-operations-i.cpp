class Solution {
public:
    int maxFrequency(vector<int>& a, int k, int numOperations) {
        int n = a.size();

        sort(a.begin(), a.end());
        int mx = *max_element(a.begin(), a.end()) + k;
        int mn = *min_element(a.begin(), a.end()) - k;

        vector<int> pref(mx + 3, 0);
        map<int, int> mp;
        for (auto x: a) {
            mp[x]++;
            int low = max(0, x - k);
            int high = x + k;
            // cout << low << " "  << high << "\n";
            pref[low]++, pref[high + 1]--;
        }

        // for (int i = 1; i <= mx; i++) {
        //     cout << pref[i] << " ";
        // }
        // cout << "\n";
        for (int i = 1; i <= mx; i++) {
            pref[i] += pref[i - 1];
        }
        int ans = 1, op = 0;
        for (int i = mn; i <= mx; i++) {
            // cout << "mpi: " << mp[i] << " ";
            int x = pref[max(i, 0)] - mp[i];
            int f = min(x, numOperations) + mp[i];
            // cout << i << " " << pref[max(i, 0)] << "\n";
            ans = max(ans, f);
        }
        
        return ans;

    }
};