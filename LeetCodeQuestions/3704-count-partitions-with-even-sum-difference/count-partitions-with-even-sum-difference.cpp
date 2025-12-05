class Solution {
public:
    int countPartitions(vector<int>& a) {
        int n = a.size();
        vector<int> suff(n);
        suff[n - 1] = a[n - 1];

        for (int i = n - 2; i >= 0; i--)
            suff[i] = suff[i + 1] + a[i];

        int pref = 0;
        int ans = 0;

        for (int i = 0; i < n - 1; i++) {
            pref += a[i];
            if (abs(pref - suff[i + 1]) % 2 == 0) 
                ans++;
        }

        return ans;
    }
};