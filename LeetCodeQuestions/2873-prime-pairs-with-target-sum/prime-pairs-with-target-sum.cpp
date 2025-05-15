class Solution {
public:
    vector<int> primes;

    void sieve(int n) {
        vector<bool> isPrime(n + 1, true);
        isPrime[1] = false;

        for (long i = 2; i <= n; i++) {
            if (isPrime[(int)i]) {
                primes.push_back((int)i);
                for (long j = 1LL * i * i; j <= n; j += i) {
                    isPrime[j] = false;
                }
            }
        }
    }

    vector<vector<int>> findPrimePairs(int n) {
        sieve(n);

        set<vector<int>> ans;
        for (int i = 0; i < primes.size(); i++) {
            int x = n - primes[i];
            if (binary_search(primes.begin(), primes.end(), x)) {
                if (x > primes[i]) {
                    ans.insert({primes[i], x});
                } else {
                    ans.insert({x, primes[i]});
                }
            }
        }

        vector<vector<int>> ans1;

        for (auto x: ans) {
            ans1.push_back(x);
        }
        return ans1;
    }
};