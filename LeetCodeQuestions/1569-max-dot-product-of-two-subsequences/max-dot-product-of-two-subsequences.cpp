class Solution {
public:
    vector<int> a, b;
    int n, m;
    int dp[500][500];

    int fn(int i, int j) {
        if (i >= n || j >= m) return INT_MIN / 2;

        if (dp[i][j] != -1) return dp[i][j];

        int skip_one = max(fn(i + 1, j), fn(i, j + 1));
        int take = a[i] * b[j] + max(fn(i + 1, j + 1), 0);

        return dp[i][j] = max(skip_one, take);
    }

    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        memset(dp, -1, sizeof(dp));

        a = nums1, b = nums2;    
        n = a.size(), m = b.size();
        
        return fn(0, 0);
    }
};