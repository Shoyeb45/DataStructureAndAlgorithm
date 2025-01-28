#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int countNumberOfSubsequence(vector<int> &arr, int target, int index = 0, int sum = 0) {
        if (index == arr.size()) {
            return sum == target;
        }

        return countNumberOfSubsequence(arr, target, index + 1, sum) + countNumberOfSubsequence(arr, target, index + 1, sum + arr[index]);
    }
};

int main() {
    int n, sum;
    cin >> n >> sum;
    vector<int> arr(n);

    for (auto &x: arr) {
        cin >> x;
    }

    Solution sol;
    
    cout << sol.countNumberOfSubsequence(arr, sum) << "\n";
    return 0;
}