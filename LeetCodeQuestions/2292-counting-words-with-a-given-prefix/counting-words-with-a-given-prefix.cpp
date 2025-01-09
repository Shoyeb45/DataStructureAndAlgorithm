class Solution {
    bool isPrefix(string &str1, string &str2) {
        if (str2.size() < str1.size()) {
            return false;
        }
        int i = 0, j = 0;

        while (i < str1.size() && j < str2.size()) {
            if (str1[i] != str2[j]) {
                break;
            }
            i++, j++;
        }
        return i >= str1.size();
    }
public:
    int prefixCount(vector<string>& words, string pref) {
        int ans = 0;
        for (string x : words) {
            ans += isPrefix(pref, x);
        }
        return ans;
    }
};