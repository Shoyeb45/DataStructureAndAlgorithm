using ll = long long;

class Solution {
public:

    long long maxProfit(vector<int>& p, vector<int>& s, int k) {
        ll ans = 0;
        int n = p.size();
        for (int i = 0; i < n; i++) 
            ans += p[i] * s[i];

        ll ans2 = 0;
        ll tmp = 0;
        vector<ll> pref(n), pref_s(n);

        pref[0] = p[0], pref_s[0] = s[0] * p[0];

        for (int i = 1; i < n; i++) {
            pref[i] = pref[i - 1] + p[i];
            pref_s[i] = pref_s[i - 1] + (p[i] * s[i]);
        }

            
        int d = k / 2;

        for (int i = 0; i < k; i++) {
            tmp += s[i] * p[i];
        }


        auto chk = [&](int i, int j) -> void {
            ll left = (i == -1 ? 0 : pref_s[i]);
            ll first = pref_s[i + d] - left;
            ll last = pref_s[j] - pref_s[j - d];

            ll t = tmp - (first + last) + (pref[j] - pref[j - d]) + left + pref_s[n - 1] - pref_s[j];
            ans = max(ans, t);
        };
        
        chk(-1, k - 1);

        for (int i = 0, j = k; j < n; j++, i++) {
            tmp -= p[i] * s[i];
            tmp += p[j] * s[j];

            chk(i, j);
        }
        return ans;
    }
};