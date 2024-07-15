#include<bits/stdc++.h>

using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
#define range(x) (x).begin(), (x).end()
typedef long long ll;
const ll mod = 1000000007;

auto init = []() { 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

int main() {
    vector<ll> fibonacci_term = {0, 1};
    int n;
    cin >> n;
    for(int i = 2; i < n; i++) {
        fibonacci_term.push_back(fibonacci_term[i - 1] + fibonacci_term[i - 2]);
    }
    for(auto x: fibonacci_term) {
        cout << x << ' ';
    }
    
    
    return 0;
}
