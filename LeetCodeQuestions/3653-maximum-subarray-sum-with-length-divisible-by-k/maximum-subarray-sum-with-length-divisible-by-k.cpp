using ll = long long;

class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        // For each i, we need j = i - p*k, and among all valid indices we need minimum pref[j] 
        int n = nums.size();
        vector<ll> pref(n + 1);

        for (int i = 1; i <= n; i++) pref[i] = pref[i - 1] + nums[i - 1];
    
     
        ll ans = LLONG_MIN;
        vector<ll> best(k, LLONG_MAX);
        best[0] = 0;

        for (int i = 1; i <= n; i++) {
            int j = i % k;
            if (best[j] != LLONG_MAX) 
                ans = max(ans, pref[i] - best[j]);

            best[j] = min(best[j], pref[i]);
        }
        return ans;
    }
};