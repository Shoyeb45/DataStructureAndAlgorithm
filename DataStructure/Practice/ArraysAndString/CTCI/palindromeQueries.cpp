#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
int prefixChar[100005][26];

void preprocess(string s) {
    loop(i, s.size()) {
        prefixChar[i + 1][s[i] - 'a']++;
    }

    for(int i = 1; i <= s.size(); i++) {
        loop(j, 26) {
            prefixChar[i][j] += prefixChar[i - 1][j];
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    cin >> q;
    string s;
    cin >> s;
    preprocess(s);
    while(q--) {
        int l, r;
        cin >> l >> r;

        int odd = 0;
        loop(i, 26) {
            if((prefixChar[r][i] - prefixChar[l - 1][i]) % 2 == 1) {
                odd++;
            }
        }

        if(odd <= 1) {
            cout << "Possible\n";
        } else {
            cout << "Impossible\n";
        }
    }
    return 0;
}
