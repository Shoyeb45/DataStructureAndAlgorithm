// URLIFY

#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
const ll mod = 1000000007;

vector<string> split(string s, char x) {
    vector<string> ans;
    string a = "";
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == x) {
            ans.push_back(a);
            a = "";
        } else {
            a += s[i];
        }
        if(i == s.size() - 1) {
            ans.push_back(a);
        }
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    getline(cin, s);
    vector<string> words = split(s, ' ');

    string ans = words[0];
    for(int i = 1; i < words.size(); i++) {
        ans = ans + "%20" + words[i];
    }
    cout << ans;
    return 0;
}
