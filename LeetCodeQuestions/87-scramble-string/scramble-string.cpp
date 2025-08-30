class Solution {
public:
    unordered_map<string, bool> mp;

    bool f(string s1, string s2) {
        string key = s1 + " " + s2;
        if (mp.find(key) != mp.end()) {
            return mp[key];
        }
        int n = s1.size();
        if (s1 == s2) {
            return mp[key] = true;
        }
        if (n <= 1) {
            return mp[key] = false;
        }

        for (int i = 1; i < n; i++) {
            bool case1 = f(s1.substr(0, i), s2.substr(n - i, i)) && f(s1.substr(i, n - i), s2.substr(0, n - i));
            bool case2 = f(s1.substr(0, i), s2.substr(0, i)) && f(s1.substr(i, n - i), s2.substr(i, n - i));
            if (case1 || case2) {
                return mp[key] = true;
            }
        }
        return mp[key] = false;
    }
    bool isScramble(string s1, string s2) {
        if (s1.size() != s2.size()) {
            return false;
        }
        if (s1.size() <= 1) {
            return s1 == s2;
        }

        return f(s1, s2);
    }
};