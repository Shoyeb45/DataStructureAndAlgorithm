#include <bits/stdc++.h>
using namespace std;
#define loop(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
const ll mod = 1000000007;

bool isSubstring(string a, string& b) {
    size_t found = a.find(b);
    return found != std::string::npos;
}
bool rotateString(string s, string g) {
    if (s.size() != g.size())
        return false;
    int common = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == g[0]) {
            common = i;
            break;
        }
    }
    cout << "Common: " << common << endl;
    int secCommon = 0;
    for (int i = common, j = 0; i < s.size(); i++, j++) {
        if (s[i] != g[j])
            return false;
        if (i == s.size() - 1) {
            secCommon = j + 1;
        }
    }
    cout << "SEcCommon: " << secCommon << endl;
    for (int i = 0, j = secCommon; i < common && j < g.size(); i++, j++) {
        if (s[i] != g[j])
            return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string a, b;
    cin >> a;
    cin >> b;


    return 0;
}
