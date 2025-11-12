class Solution {
public:
    bool hasSameDigits(string s) {
        while (s.size() > 2) {
            string temp = "";

            for (int i = 0; i < s.size() - 1; i++) {
                int num = (s[i] + s[i + 1] - 2 * (int)'0') % 10;
                temp += num + '0';
            }
            s = temp;
        }

        return s[0] == s[1];
    }
};