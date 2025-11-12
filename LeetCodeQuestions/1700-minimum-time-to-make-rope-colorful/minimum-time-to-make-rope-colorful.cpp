class Solution {
public:
    int minCost(string s, vector<int>& a) {
        int n = a.size();
        int ans = 0;
        for (int i = 1; i < n; i++) {
            if (s[i] == s[i - 1]) {
                int j = i;
                int sum = a[i - 1], mx_ele = a[i - 1];
                while (j < n && s[i] == s[j]) {
                    sum += a[j], mx_ele = max(mx_ele, a[j]);
                    j++;
                }
                ans += max(0, sum - mx_ele);
                i = j - 1;
            }
        }
        return ans;
    }
};