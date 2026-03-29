class Solution {
public:
    bool canBeEqual(string s1, string s2) {

        bool taken[4] = {false};

        for (int i = 0; i < 4; i++) {
            if (s1[i] == s2[i]) continue;
            int j = -1;
            for (int k = 0; k < 4; k++) {
                if (s1[i] == s2[k] && abs(k - i) == 2) {
                    j = k;
                }
            }
            if (j == -1) return false;
        }     
        return true;
    }
};