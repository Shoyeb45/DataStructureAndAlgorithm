class Solution {
public:
    int findNumberOfLIS(vector<int>& a) {
        int n = a.size();
        vector<int> cnt(n, 1), len(n, 1);

        int mxLen = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (a[i] > a[j]) {
                    if (len[j] + 1 > len[i]) {
                        len[i] = len[j] + 1;
                        cnt[i] = cnt[j];
                    }
                    else if (len[j] + 1 == len[i]) {
                        cnt[i] += cnt[j];
                    }
                }
            }
            mxLen = max(mxLen, len[i]);
        }
        
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (len[i] == mxLen) {
                ans += cnt[i];
            }
        }

        return ans;
    }
};