#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
const ll mod = 1000000007;

void insertion_sort(vector<int> &a) {
    int n = a.size();
    for(int i = 1; i < n; i++) {
        int j = i;
        while(j >= 1 && a[j] < a[j - 1]) {
            swap(a[j - 1], a[j]);
            j--;
        }
    }
}

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    loop(i, n)
        cin >> a[i];

    insertion_sort(a);
    loop(i, n)
        cout << a[i] << ' ';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    tt = 1;
    // cin >> tt;

    while (tt--) {
        solve();
    }
    
    return 0;
}
