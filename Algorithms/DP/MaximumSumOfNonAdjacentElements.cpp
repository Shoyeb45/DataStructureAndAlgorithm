#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
const ll mod = 1000000007;

int n;
int ans;
vector<int> a;

void f(vector<int> &a, int sum, bool last, int index) {
    if(index == n) {
        ans = max(ans, sum);
        return;
    }

    if(last) {
        f(a, sum, 0, index + 1);
    } else {
        f(a, a[index] + sum, 1, index + 1);
        f(a, sum, 0, index + 1);
    }
}
void solve() {
    cin >> n;
    a.resize(n);
    for(auto &x: a) {
        cin >> x;
    }
    ans = INT_MIN;
    f(a, 0, 0, 0);
    cout << ans << '\n';
}

int main() {
    NFS
    int tt;
    tt = 1;
    cin >> tt;

    while (tt--) {
        solve();
    }
    
    return 0;
}
