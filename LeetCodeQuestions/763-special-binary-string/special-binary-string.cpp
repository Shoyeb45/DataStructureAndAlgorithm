class Solution {
public:
    string makeLargestSpecial(string s) {
        if (s.empty()) {
            return "";
        }

        string temp = "";
        vector<string> a;
        int cnt = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') {
                cnt++;
                temp += s[i];
            }
            else {
                temp += s[i];
                cnt--;
            }

            if (cnt == 0) {
                string t = "";
                for (int k = 1; k < temp.size() - 1; k++) {
                    t += temp[k];
                }

                string ans = makeLargestSpecial(t);
                a.push_back('1' + ans + '0');
                temp = "";
            }
        }

        sort(a.rbegin(), a.rend());

        string fin = "";
        for (auto x : a) {
            fin += x;
        }

        return fin;
    }
};