#define MAX_PRIME (int)(5e6 + 2)

class Solution {
public:

    vector<bool> isPrime;
    void sieve(int n) {
        isPrime.resize(n + 1, true);
        isPrime[1] = false;

        for (long i = 2; 1LL * i * i <= n; i++) {
            if (isPrime[(int)i]) {
                for (long j = i * i; j <= n; j += i) {
                    isPrime[(int)j] = false;
                }
            }
        }
    }
    int countPrimes(int n) {

        sieve(n);
        int ans = 0;
        for (int i = 2; i < n; i++) {
            ans += isPrime[i];
        }

        return ans;
    }
};