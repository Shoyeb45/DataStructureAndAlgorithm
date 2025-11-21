class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        vector pref(n, vector<bool> (26, false)); 
        vector suff(n, vector<bool> (26, false)); 

        auto to_idx = [&](char ch) -> int {
            return ch - 'a';
        };

        pref[0][to_idx(s[0])] = true;
        suff[n - 1][to_idx(s[n - 1])] = true;

        for (int i = 1; i < n; i++) {
            int idx = to_idx(s[i]);
            for (int j = 0; j < 26; j++) {
                pref[i][j] = pref[i - 1][j] | (idx == j);
            }
        }
        for (int i = n - 2; i >= 0; i--) {
            int idx = to_idx(s[i]);
            for (int j = 0; j < 26; j++) {
                suff[i][j] = suff[i + 1][j] | (idx == j);
            }
        }

        int ans = 0;
        map<int, set<int>> mp;

        for (int i = 1; i < (int) s.size() - 1; i++) {
            for (int j = 0; j < 26; j++) {
                bool left = pref[i - 1][j];
                bool right = suff[i + 1][j];
                if (left && right)
                    mp[to_idx(s[i])].insert(j);
            }
        }

        for (auto it: mp) {
            ans += it.second.size();
        }
        return (int) ans;
    }
};