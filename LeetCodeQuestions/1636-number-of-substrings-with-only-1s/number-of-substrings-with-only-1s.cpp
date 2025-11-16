const int MOD = (int) 1e9 + 7;
using ll = long long;

class Solution {
public:
    // a^b % mod
    int mod_pow(int base, int b, int mod) {
        ll ans = 1;
        ll a = base;

        while (b > 0) {
            if ((b & 1)) {
                ans = (ll)ans * a % mod;
            }
            a = (ll)a * a % mod;
            b >>= 1;
        }
        return (int) ans;
    }

    

    int numSub(string s) {
        ll ans = 0;
        int n = s.size();

        int mod_inverse_2 = 500000004;
        for (int i = 0; i < n; ) {
            if (s[i] == '0') {
                i++;
                continue;
            }

            int j = i;
            while (j < n && s[j] == s[i]) {
                j++;
            }
            int cnt = j - i;
            i = j;

            ll sum = (ll)cnt * (cnt + 1) % MOD;
            sum = (ll)sum * mod_inverse_2 % MOD;
            ans = (ll)ans + sum % MOD; 
        }
        return (int) ans;
    }
};