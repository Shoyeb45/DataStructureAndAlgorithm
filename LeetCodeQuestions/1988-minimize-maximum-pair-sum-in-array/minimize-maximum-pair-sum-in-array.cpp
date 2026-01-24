class Solution {
public:
    int minPairSum(vector<int>& a) {
        int ans = INT_MIN;
        sort(a.begin(), a.end());
        for (int left = 0, right = a.size() - 1; left < right; left++ ,right--) {
            ans = max (ans, a[left] + a[right]);
        }
        return ans;
    }
};