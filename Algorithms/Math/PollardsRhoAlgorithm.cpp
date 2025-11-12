# include<bits/stdc++.h>
using namespace std;

typedef long long  ll;
typedef unsigned long long ull;


ll mod_mul(ll a, ll b, ll M){
    //  (a * b) % c congruent to a*b - floor(ab / c) * c
    long long res = a * b - M * ll(1.L / M * a * b);
	return res + M * (res < 0) - M * (res >= (long long)M); // for precision handling
}

// Fast Exponentiation
ll mod_pow(ll a, ll d, ll mod) {
    ll res = 1;
    
    while (d > 0) {
        if (d & 1) { 
            res = (ll)res * a % mod;
        }
        a = (ll)a * a % mod;
        d >>= 1;
    }
    return res;
}

// Miller-Rabin primality test
bool is_prime(ll n) {
    if (n < 2) return false;
    for (ll p : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
        if (n % p == 0) {
            return n == p;
        }
    }

    // From Fermat's little theorem we have, 
    // a^(n - 1) == 1 (mod n), where a is between 1 to n - 1

    ll d = n - 1, s = 0;
    while ((d & 1) == 0) {
        d >>= 1;
        s++;
    }
    for (ll a : {2, 325, 9375, 28178, 450775, 9780504, 1795265022}) {
        if (a % n == 0) { 
            continue; 
        }
        ll x = mod_pow(a, d, n);
        if (x == 1 || x == n - 1) { 
            continue;
        }
        bool comp = true;
        for (int r = 1; r < s; r++) {
            x = (ll)x * x % n;
            if (x == n - 1) {
                comp = false;
                break;
            }
        }
        if (comp) {
            return false;
        }
    }
    return true;
}

// Mersenne twister engine to generate random number between a range
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

// Pollard's Rho function
ll pollard(ll n) {
    if (n % 2 == 0) return 2;
    ll x = uniform_int_distribution<ll>(2, n - 2)(rng); // random starting point of the series: x_0, x_1, x_2, ....
    ll y = x;
    ll c = uniform_int_distribution<ll>(1, n - 1)(rng); // random polynomial constant, f(x) = (x^2 + c) % n
    ll d = 1;
    auto f = [&](ll x) -> ll { 
        return (mod_mul(x, x, n) + c) % n;
    };
    // x -> slow pointer, y -> fast pointer
    while (d == 1) {
        x = f(x);    // move x by one step
        y = f(f(y)); // move y by two step
        d = __gcd(abs(x - y), n);
        if (d == n) { 
            return pollard(n); // failed attempt, we need to do again with another random value.
        }    
    }

    // since our function is % n, so we will get some point where our x = y.
    return d;
}

// Factorization
vector<ll> factorize(ll n) {
    if (n == 1) {
        return {};
    }

    if (is_prime(n)) {
        return {n};
    }

    ll d = pollard(n);
    vector<ll> left = factorize(d);
    vector<ll> right = factorize(n / d);
    left.insert(left.end(), right.begin(), right.end());
    return left;
}


int main() {
    ll n;
    cin >> n;
    
    vector<ll> factors = factorize(n);
    cout << "Factors of n: \n"; 
    for (auto x : factors) {
        cout << x << " ";
    }
    cout << "\n";
    return 0;
}