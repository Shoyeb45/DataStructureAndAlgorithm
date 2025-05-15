class Solution {
public:
    vector<int> primeFactors[1001];

    void genFactors() {
        vector<int> isPrime(1001, true);
        isPrime[1] = 0;
        for (int i = 2; i <= 1000; i++) {
            if (isPrime[i]) {
            primeFactors[i].push_back(i);
                for (int j = 2 * i; j <= 1000; j += i) {
                    isPrime[j] = false;
                    primeFactors[j].push_back(i);
                }
            }
        }

    }

    int distinctPrimeFactors(vector<int>& nums) {
        genFactors();    
        
        set<int> ans;

        for (auto x: nums) {
            if (x < 2) {
                continue;
            }
            ans.insert(primeFactors[x].begin(), primeFactors[x].end());
        }
        return (int)ans.size();
    }
};