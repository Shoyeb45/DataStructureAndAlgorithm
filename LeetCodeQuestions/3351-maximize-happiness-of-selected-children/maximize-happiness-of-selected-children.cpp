class Solution {
public:
    long long maximumHappinessSum(vector<int>& h, int k) {
        long long ans = 0;
        sort(h.rbegin(), h.rend());

        for (int i = 0; i < k; i++) {
            int tmp = max(0, h[i] - i);
            ans += tmp;
        }     
        return ans;
    }
};


// 2 4 10
// 10 + 3 + 0 = 13
// 2 + 3 + 8

// x1 <= x2 <= x3 <= .... <= xn
// 