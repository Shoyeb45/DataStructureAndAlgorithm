#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
const ll mod = 1000000007;

void bubble_sort(vector<int> &a) {
    bool swapped = false;
    for(int i = 0; i < a.size(); i++) {
        swapped = false;
        for(int j = 0; j < a.size() - i - 1; j++) {
            if(a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                swapped = true;
            }
        }
        if(!swapped) {
            break;
        }
    }

}
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    loop(i, n)
        cin >> a[i];
    
    bubble_sort(a);
    loop(i, n) {
        cout << a[i] << ' ';
    }
    cout << '\n';
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
