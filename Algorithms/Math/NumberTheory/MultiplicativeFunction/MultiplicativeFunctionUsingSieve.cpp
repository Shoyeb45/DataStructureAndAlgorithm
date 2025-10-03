# include<bits/stdc++.h>
using namespace std;
std::vector <int> prime;
bool is_composite[MAXN];
int func[MAXN], cnt[MAXN];

void sieve (int n) {
	std::fill (is_composite, is_composite + n, false);
	func[1] = 1;
	for (int i = 2; i < n; ++i) {
		if (!is_composite[i]) {
			prime.push_back(i);
			func[i] = 1; cnt[i] = 1;  // prime number
		}
		for (int j = 0; j < prime.size () && i * prime[j] < n; ++j) {
			is_composite[i * prime[j]] = true;
			if (i % prime[j] == 0) {
				func[i * prime[j]] = (func[i] / cnt[i]) * (cnt[i] + 1);
				cnt[i * prime[j]] = cnt[i] + 1;
				break;
			} else {
				func[i * prime[j]] = func[i] * func[prime[j]];
				cnt[i * prime[j]] = 1;
			}
		}
	}
}