#include<bits/stdc++.h>
using namespace std;

/// @author Shoyeb Ansari
/// @brief Data structure for prefix sum queries
/// @tparam dt : Data type
template<typename dt>
class PrefixArray {
private:
    vector<dt> prefix;

    PrefixArray(vector<dt> &arr) {
        prefix.resize(arr.size(), 0);
        prefix[0] = arr[0];

        for (int i = 1; i < arr.size(); i++) {
            prefix[i] += prefix[i - 1] + arr[i];
        }
    }

    /// @brief 
    /// @param L left index
    /// @param r right index
    /// @return same as input data type
    dt query(int L, int r) {
        if (l == 0) {
            return prefix[r];
        }
        return prefix[r] - prefix[l - 1];
    }
    
};