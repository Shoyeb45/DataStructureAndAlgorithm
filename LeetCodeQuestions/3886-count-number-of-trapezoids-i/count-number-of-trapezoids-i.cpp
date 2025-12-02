const int mod = (int) 1e9 + 7;
using ll = long long;

const int mod_inv_2 = 500000004;

class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        ll ans = 0;
        map<int, int> mp;
        for (auto x: points) mp[x[1]]++;

        auto cnt = [&](int x) -> ll {
            ll ans = x;
            ans = (ll) ans * (x - 1) % mod;
            ans = (ll) ans * mod_inv_2 % mod;
            return ans % mod;
        };

        vector<ll> a;
        for (auto x: mp) a.push_back(cnt(x.second));

        vector<ll> suff(a.size());
        suff[a.size() - 1] = a.back();
        for (int i = a.size() - 2; i >= 0; i--) suff[i] = suff[i + 1] + a[i];

        for (int i = 0; i < a.size(); i++) {
            cout << a[i] << " ";
            ll t1 = a[i]; 
            ll t2 = i + 1 >= a.size() ? 0: suff[i + 1];
            ll tmp = (ll) t1 * t2 % mod;  
            ans = (ans + tmp) % mod;
        }
        return (int) ans;
    }
};