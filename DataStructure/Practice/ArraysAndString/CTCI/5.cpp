// One away

#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
const ll mod = 1000000007;

bool oneAway(string a, string b) {
    
    if(a.size() == b.size()) {
        int distinct = 0;
        loop(i, a.size()) {
            if(a[i] != b[i])
                distinct++;
        }

        if(distinct <= 1)
            return true;
        return false;
    } 
    
    int distinct = 0;
    int i = 0, j = 0;
    string smaller, bigger;
    if(a.size() > b.size()) {
        bigger = a;
        smaller = b;
    } else {
        bigger = b;
        smaller = a;
    }
    if(bigger.size() - smaller.size() > 1)
            return false;
    
    while (i < smaller.size())
    {
        if(smaller[i] != bigger[j]) {
            distinct++;
            if(distinct > 1)
                return false;
        } 
        else
            i++;
        j++;
    }
    
    return true;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string a, b;
    cin >> a;
    cin >> b;
    if(oneAway(a, b))
        cout << "TRUE\n";
    else
        cout << "FALSE\n";
    
    return 0;
}
