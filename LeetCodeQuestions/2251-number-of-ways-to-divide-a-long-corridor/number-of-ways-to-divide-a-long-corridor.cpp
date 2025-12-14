class Solution {
public:
    int numberOfWays(string corridor) {
        int n = corridor.size();
        int cnt = 0;
        for (char ch: corridor) cnt += (ch == 'S');

        if (cnt <= 1) {
            return 0;
        }


        int i;
        for (i = 0; i < n; i++) 
            if (corridor[i] == 'S') break;
        
        cnt = 0;
        long long ans = 1;
        const int mod = (int)1e9 + 7;

        for (; i < n; i++) {
            if (corridor[i] == 'S') {
                ans = (long long)ans * (cnt + 1) % mod;
                cnt = 0;

                int tmp = 0;
                int j = i;
                while (j < n && tmp != 2) {
                    tmp += corridor[j] == 'S';
                    j++;
                }
                if (tmp <= 1)
                    ans = 0;
                                    
                i = j - 1;
            } else {
                cnt++;
            }
        }

        return (int) ans;
    }
};