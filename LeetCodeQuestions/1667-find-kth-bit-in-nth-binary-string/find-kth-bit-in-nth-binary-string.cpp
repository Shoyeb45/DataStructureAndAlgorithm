class Solution {
public:
    char findKthBit(int n, int k) {
        auto invert = [&](string &s) -> string {
            string ans = "";
            for (int i = 0; i < s.size(); i++) {
                int bit = s[i] - '0';
                bit = 1 - bit;
                ans += bit + '0';
            }
            return ans;
        };

        auto find_next_string = [&](string s_p) -> string {
            string p = invert(s_p);
            reverse(p.begin(), p.end());
            return s_p + '1' + p;
        };

        string nth = "0";
        for (int i = 2; i <= n; i++) {
            nth = find_next_string(nth);
        }
        return nth[k - 1];
    }
};