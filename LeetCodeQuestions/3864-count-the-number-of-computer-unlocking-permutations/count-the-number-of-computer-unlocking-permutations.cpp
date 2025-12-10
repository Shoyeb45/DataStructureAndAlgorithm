const int mod = (int)1e9 + 7;

class Solution {
public:
    int countPermutations(vector<int>& a) {
        int n = a.size();
        int mn = *min_element(a.begin(), a.end());

        if (a[0] != mn)
            return 0;
            
        int cnt = 0;
        for (auto &x: a) 
            cnt += (x == mn);

        if (cnt > 1) 
            return 0;

        long long ans = 1;

        for (int i = 2; i <= n - 1; i++) {
            ans = (long long) ans * i % mod;
        }
        return (int) ans;
    }
};