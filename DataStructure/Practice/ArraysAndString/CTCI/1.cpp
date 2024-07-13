// Unique characters

#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
const ll mod = 1000000007;

// With Additional data structure
// bool isUnique(string s) {
//     map<char, int> mp;
//     for(auto &ch: s)
//         mp[ch]++;

//     if(mp.size() == s.size())
//         return true;
    
//     return false;
        // TC : O(|s|), SC: O(|s|)  
// }

// Without additional data structure
bool isUnique(string s) {
    for(int i = 0; i < s.size(); i++) {
        for(int j = i + 1; j < s.size(); j++) {
            if(s[i] == s[j]) {
                return false;
            }
        }
    }
    return true;

    // TC : O(|s|^2), SC: O(1)  
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--) {
        string s; cin >> s;
        if(isUnique(s))
            cout << "Unique" << endl;
        else
            cout << "Not Unique" << endl;
    }
    
    return 0;
}
