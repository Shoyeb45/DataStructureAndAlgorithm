class Solution {
public:
    int maxArea(vector<int>& a) {
        int ans = INT_MIN;
        for (int l = 0, r = a.size() - 1; l < r; ) {
            int temp = (r - l) * min(a[l], a[r]);
            ans = max(ans, temp);

            if (a[l] < a[r]) {
                l++;
            }
            else {
                r--;
            }
        }

        return ans;
    }
};