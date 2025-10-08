class Solution {
public:
    vector<int> successfulPairs(vector<int>& a, vector<int>& potions, long long success) {
        vector<long long> b;
        for (auto x: potions) {
            b.push_back((long long) x);
        }

        sort(b.begin(), b.end());
        int n = a.size(), m = b.size();
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            long long x = (success + a[i] - 1) / a[i];
            // cout << "x :" << x << "\n";
            int j = lower_bound(b.begin(), b.end(), x) - b.begin(); 
            // cout << j << '\n';/
            ans[i] = m - j;
        }
        return ans;
    }
};