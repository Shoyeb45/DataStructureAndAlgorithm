class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int r = 0, l = 0, dash = 0;
        for (char ch: moves) {
            r += ch == 'R';
            l += ch == 'L';
            dash += ch == '_';
        }

        // cout << " - " << dash << " r " << r << " l " << l <<"\n";
        if (r > l) {
            return abs(r + dash - l);
        }

        return abs(l + dash - r);
    }
};