#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
const ll mod = 1000000007;

int partition(vector<int> &a, int low, int high) {
    int pivot = a[high];
    int i = low - 1;
    for(int j = low; j <= high; j++) {
        if(a[j] < pivot) {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[high]);
    return i + 1;
}

void quick_sort(vector<int> &a, int low, int high) {
    if(low < high) {
        int pi = partition(a, low, high);
        quick_sort(a, low, pi - 1);
        quick_sort(a, pi + 1, high);
    }
}
void solve() {
    int n; cin >> n;
    vector<int> a(n);
    loop(i, n)
        cin >> a[i];
    quick_sort(a, 0, n - 1);
    loop(i, n)
        cout << a[i] << ' ';
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
