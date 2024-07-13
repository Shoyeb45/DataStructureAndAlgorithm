// Permutation  check

#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
const ll mod = 1000000007;

bool isPermutation(string orig, string perm) {

    if(orig.size() != perm.size()) 
        return false;
        
    sort(orig.begin(), orig.end());
    sort(perm.begin(), perm.end());

    if(orig == perm)
        return true;
    return false;
    // TC: O(|orig| * log(|orig|))
}

bool isPerm(string a, string b) {
    map<char, int> m1;
    for(char ch: a)
        m1[ch]++;
    
    map<char, int> m2;
    for(char ch: b)
        m2[ch]++;

    if(m1.size() != m2.size())
            return false;
    for(int i = 0; i < a.size(); i++) {
        if(m1[a[i]] != m2[a[i]])
            return false;
    }

    return true;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--) {
        string s, a; cin >> s >> a;
        if(isPermutation(s, a)) 
            cout << "Strings are permutation of one another\n";
        else
            cout << "Strings are not permutation\n";
    }
    
    return 0;
}
