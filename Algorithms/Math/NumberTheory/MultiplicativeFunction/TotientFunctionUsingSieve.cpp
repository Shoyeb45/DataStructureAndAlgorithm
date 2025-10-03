using namespace std;

vector<int> totientFunc(int n) {
    vector<int> phi(n+1), primes;
    vector<bool> isComposite(n+1);
    vector<int> primes;
    phi[1] = 1;

    for (int i = 2; i <= n; i++) {
        if (!isComposite[i]) {
            primes.push_back(i);
            phi[i] = i - 1;  // φ(p) = p-1 for prime
        }
        for (int p : primes) {
            if (i * 1LL * p > n) break;
            isComposite[i * p] = true;
            if (i % p == 0) {
                // Case 3: p divides i
                phi[i * p] = phi[i] * p;
                break;
            } else {
                // Case 2: gcd(i, p) = 1
                phi[i * p] = phi[i] * phi[p];
            }
        }
    }
}