// Palindrome PErmuatation

#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;

// bool isPalPerm(string s) {
//     int n = s.size();
//     map<char, int> m;
//     for(auto &ch: s) 
//         m[ch]++;

//     if(m.size() == 1)
//         return true;
//     bool ans = false;

//     if(n % 2 == 0) {
//         for(auto it: m) {
//             if(it.second % 2 == 0) {
//                 ans = true;
//             } else {
//                 ans = false;
//                 break;
//             }
//         }
//     } else {
//         int cnt2 = 0, cnt1 = 0;
//         for(auto it: m) {
//             if(it.second % 2 == 0) 
//                 cnt2 = it.second/2;
//             else if(it.second == 1)
//                 cnt1++;
//         }

//         if(cnt2 == n/2 && cnt1 == 1)
//             ans = true;
//     }
//     return ans;
// }

// Using bit masking
bool isPalPerm(string s) {
    int mask = 0;
    for(char ch: s) {
        int pos = ch - 'a';
        mask ^= (1 << pos);
    }
    return !(mask & (mask - 1));
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;

    if(isPalPerm(s))
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}
