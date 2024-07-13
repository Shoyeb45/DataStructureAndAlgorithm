#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
const ll mod = 1000000007;

string numToStr(int cnt) {
    string ans = "";
        if(cnt == 1)
            return ans;
        while(cnt >= 1) {
            ans += (cnt % 10) + '0';
            cnt /= 10;
        }
        reverse(ans.begin(), ans.end());
        return ans;
}
string compress(string a) {
    string s = "";
        s += a[0];
        if(a.size() == 1)
            return a;
        int cnt = 1;
        for(int i = 1; i < a.size(); i++) {
            if(a[i] == s[s.size() - 1]) {
                cnt++;
            } else {
                s += numToStr(cnt);
                s += a[i];
                cnt = 1;
            }
        }
        s += numToStr(cnt);
        for(int i = 0; i < s.size(); i++) {
            a[i] = s[i];
        }
        return s;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;
        cout << compress(s);
    }
    
    return 0;
}
