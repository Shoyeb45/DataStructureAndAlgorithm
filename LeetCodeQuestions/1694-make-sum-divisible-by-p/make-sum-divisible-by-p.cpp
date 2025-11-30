#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);

class Solution {
public:
    int minSubarray(vector<int>& a, int p) {
        NFS
        int sum = 0;
        for (auto& x: a) {
            sum = (sum + x) % p;
            x %= p;    
        }

        if (sum == 0) return 0;

        // need to remove sum + k * p, where k >= 0
        // Need to find the mininum length subarray for above
        // sum[l:r] = sum + (p * k)
        // pref_r - pref_{l-1} = sum + (p * k)
        // pref_r - (sum + p * k) = pref_{l-1}
        // pr - pl = sum
        // pr - sum = pl
        int n = a.size();

        vector<long long> pref(n + 1);

        for (int i = 1; i <= n; i++) pref[i] = (pref[i - 1] + a[i - 1]);
        int ans = INT_MAX;
        for (int i = 1; i <= n; i++) {
            cout << pref[i] << " ";
        }

        map<long long, int> mp;
        mp[0] = 0;

        for (int i = 1; i <= n; i++) {
            long long temp = (pref[i] - sum + p) % p;
            if (mp.find(temp % p) != mp.end()) {
                ans = min(ans, i - mp[temp % p]);
            }

            mp[pref[i] % p] = i;
        }

        return ans == n || ans == INT_MAX ? -1: ans;
    }
};