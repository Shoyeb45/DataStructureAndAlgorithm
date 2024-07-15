#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
const ll mod = 1000000007;

vector<int> merge(vector<int> &a1, vector<int> &a2) {
    vector<int> ans(a1.size() + a2.size());
    int i = 0, j = 0, k = 0;
    while(i < a1.size() && a2.size()) {
        if(a1[i] < a2[j]) {
            ans[k++] = a1[i++];
        } else {
            ans[k++] = a2[j++];
        }
    }
    while(i == a1.size() && j < a2.size()) {
        ans[k++] = a2[j++];
    }
    
    while(j == a2.size() && i < a1.size()) {
        ans[k++] = a1[i++];
    }
    return ans;
}
vector<int> merge_sort(vector<int> &a) {
    if(a.size() == 1) 
        return a;
    
    vector<int> temp_A;
    vector<int> temp_B;
    int j = 0;
    loop(i, (a.size() + 1)/2) {
        temp_A.push_back(a[j++]);
    }
    for(int i = (a.size() + 1)/2; i < a.size(); i++) {
        temp_B.push_back(a[j++]);
    }

    vector<int> sorted_a = merge_sort(temp_A);
    vector<int> sorted_b = merge_sort(temp_B);
    vector<int> final = merge(sorted_a, sorted_b);
    return final;
}   

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    loop(i, n)
        cin >> a[i];

    vector<int> c = merge_sort(a);
    
    loop(i, a.size())
        cout << c[i] << ' ';
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
