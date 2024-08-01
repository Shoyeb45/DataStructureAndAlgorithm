#include<bits/stdc++.h>
using namespace std;

#define loop(i, n) for(int i = 0; i < n; i++)
#define range(x) (x).begin(), (x).end()
typedef long long ll;
const int mod = 1e8;

auto init = []() { 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();


int n1, n2, k1, k2;

ll dp[101][101][11][2];
// 1 - FootMan
// 0 - Horseman
ll f(int numOfFoot, int numOfHorse, int streak, bool last) {
    if(numOfFoot == 0 && numOfHorse == 0) {
        return 1;
    }

    if(dp[numOfFoot][numOfHorse][streak][last] != -1) {
        return dp[numOfFoot][numOfHorse][streak][last];
    }
    ll ans = 0;
    if(numOfFoot > 0 && (last == 0 || streak < k1)) {
        ans  = (ans + f(numOfFoot - 1, numOfHorse, (last == 0 ? 1: streak + 1), 1) % mod) % mod;
    }

    if(numOfHorse > 0 && (last == 1 || streak < k2)) {
        ans = (ans + f(numOfFoot, numOfHorse - 1, (last == 1 ? 1 : streak + 1), 0) % mod) % mod;
    }

    dp[numOfFoot][numOfHorse][streak][last] = ans;
    return ans;
}
void solve() {
    cin >> n1 >> n2 >> k1 >> k2;
    memset(dp, -1, sizeof(dp));

    cout << f(n1, n2, 0, 0) << '\n';
}

int main() {
    int tt;
    tt = 1;
    // cin >> tt;

    while(tt--) {
        solve();
    }
    
    return 0;
}
