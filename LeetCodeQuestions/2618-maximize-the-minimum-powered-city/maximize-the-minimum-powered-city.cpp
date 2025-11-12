using ll = long long;

class Solution {
public:
    long long maxPower(vector<int>& a, int r, int k) {
        int n = a.size();
        vector<ll> pref(n + 2);
        for (int i = 1; i <= n; i++) {
            pref[i] = pref[i - 1] + a[i - 1];
        }
    
        vector<ll> p(n + 2);
        for (int i = 1; i <= n; i++) {
            p[i] = pref[i] - pref[max(i - r - 1, 0)] + pref[min(n, i + r)] - pref[i];
        }

        ll low = 0, high = 1e12;

        ll ans = 0;
        for (int i = 1; i <= n; i++) {
            cout << p[i] << " \n"[i == n];
        }

        auto check = [&](ll minPower) -> bool {
            vector<ll> diff(n + 1, 0); 
            ll added = 0;               
            ll used = 0;               

            for (int i = 0; i < n; ++i) {
                added += diff[i]; 

                ll curr = p[i + 1] + added;
                if (curr < minPower) {
                    ll need = minPower - curr;
                    used += need;
                    if (used > k) return false;

                    added += need;
                    int j = i + r; 
                    if (j + r + 1 < n) {
                        diff[j + r + 1] -= need; 
                    }
                }
            }
            return true;
        };

        while (low <= high) {
            ll mid = low + (high - low) / 2;
            if (check(mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};