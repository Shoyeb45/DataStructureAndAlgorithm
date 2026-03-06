class Solution {
public:
    bool checkOnesSegment(string s) {
        int seg = 0;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                seg++;
                int j = i;
                while (j < n && s[j] == '1') j++;
                i = j - 1;
            }
        }
        return seg == 1;
    }
};