#include<bits/stdc++.h>
using namespace std;


std::ostream& operator<<(std::ostream& os, vector<int> &vec) {
    for (auto x : vec) {
        os << x << " ";
    }
    cout << "\n";
}

void printUniqueSubsets(
    map<int, int> &mp,               // Map to store the element and frequency
    std::map<int, int>::iterator it, // Iterator
    vector<int> &a                   // Temporary array to store the values
) {
    if (it == mp.end()) {
        cout << a;
        return;
    }

    int val = it -> first;
    int freq = it -> second;

    printUniqueSubsets(mp, next(it), a);
    
    for (int i = 0; i < freq; i++) {
        a.push_back(val);
        printUniqueSubsets(mp, next(it), a);
    }

    for (int i = 0; i < freq; i++) {
        a.pop_back();
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);

    map<int, int> mp;
    for (auto &x: arr) {
        cin >> x;
        mp[x]++;
    }

    vector<int> a;

    printUniqueSubsets(mp, mp.begin(), a);
    return 0;
}