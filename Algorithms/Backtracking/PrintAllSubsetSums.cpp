#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> allSubset;

void printAllsubsetSum(vector<int> &arr, vector<int> &a, int index = 0) {
    // Base case
    if (index >= arr.size()) {
        allSubset.push_back(a);
        return;
    }

    // Don't pick
    printAllsubsetSum(arr, a, index + 1);

    // Pick the element
    a.push_back(arr[index]);
    printAllsubsetSum(arr, a, index + 1);
    a.pop_back();
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto &x : arr) {
        cin >> x;
    } 

    vector<int> temp;
    printAllsubsetSum(arr, temp);
    cout << "Number of subset : " << allSubset.size() << "\n";
    for (auto x : allSubset) {
        int sum = 0;
        cout << "[";
        for (int i = 0; i < x.size(); i++) {
            sum += x[i];
            cout << x[i] << (i == x.size() - 1 ? "": ", ");
        }
        cout << "] -> Sum : " << sum << "\n";
    }
    return 0;
}