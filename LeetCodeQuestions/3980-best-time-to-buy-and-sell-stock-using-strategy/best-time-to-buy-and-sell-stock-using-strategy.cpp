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

        ans = max(
            tmp - (pref_s[k - 1] - pref_s[k - 1 - d] + pref_s[d - 1]) + (pref[k - 1] - pref[k - 1 - d]) + pref_s[n - 1] - pref_s[k - 1], 
            ans
        );

        cout << tmp - (pref_s[k - 1] - pref_s[k - 1 - d] + pref_s[d - 1]) + (pref[k - 1] - pref[k - 1 - d]) + pref_s[n - 1] - pref_s[k - 1] << "\n";

        auto chk = [&](int i, int j) -> void {
            ll first = pref_s[i + d] - pref_s[i];
            ll last = pref_s[j] - pref_s[j - d];

            ll t = tmp - (first + last) + (pref[j] - pref[j - d]) + (pref_s[i]) + (pref_s[n - 1] - pref_s[j]);
            cout << t << "\n";
            ans = max(
                ans,
                t
            );
        };

        for (int i = 0, j = k; j < n; j++, i++) {
            tmp -= p[i] * s[i];
            tmp += p[j] * s[j];

            chk(i, j);
        }
        return ans;
    }
};