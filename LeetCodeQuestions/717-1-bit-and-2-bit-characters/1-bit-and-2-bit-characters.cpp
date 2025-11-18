class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n = bits.size();
        
        int i = 0;
        for (i = 0; i < n - 1; ) {
            int x = bits[i];
            if (i + 1 < n) {
                x = 10 * x + bits[i + 1];
            }
            if (x == 10 || x == 11) {
                i += 2;
            } else {
                i++;
            }
        }
        // cout << i << "\n";
        return i == n - 1; 
    }
};