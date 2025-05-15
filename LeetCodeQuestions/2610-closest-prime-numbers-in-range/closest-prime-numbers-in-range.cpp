
class Solution {
public:
    vector<int> primes;

    void sieve(int n, int left) {
        vector<bool> isPrime(n + 1, true);
        isPrime[1] = false;

        for (long i = 2; i <= n; i++) {
            if (isPrime[(int)i]) {
                if (i >= left) {
                    primes.push_back((int)i);
                }
                for (long j = 1LL * i * i; j <= n; j += i) {
                    isPrime[j] = false;
                }
            }
        } 
    }

    int lb(vector<int> primes, int num) {
        int low = 0, high = primes.size() - 1;
        int ans = 0; 
        // num1 >= left

        while (low < high) {
            int mid = (low + high) / 2;

            if (primes[mid] >= num) {
                ans = mid; 
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return primes[ans];
    }

    int ub(vector<int> primes, int num) {
        int low = 0, high = primes.size() - 1;
        int ans = high; 
        // primes[mid] <= right

        while (low < high) {
            int mid = (low + high) / 2;

            if (primes[mid] <= num) {
                ans = mid; 
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return primes[ans];
    }

    
    vector<int> closestPrimes(int left, int right) {
        if (left == right) {
            return {-1, -1};
        }

        sieve((left > right? left: right), left);
        
        if (primes.empty() || primes.size() == 1) {
            return {-1, -1};
        }


        int num1 = 0, num2 = 0;
        int diff = INT_MAX;

        for (int i = 0; i < primes.size() - 1; i++) {
            if (primes[i + 1] - primes[i] < diff) {
                diff = primes[i + 1] - primes[i];
                num1 = primes[i], num2 = primes[i + 1];
            }
        }        
        return {num1, num2};
    }
};