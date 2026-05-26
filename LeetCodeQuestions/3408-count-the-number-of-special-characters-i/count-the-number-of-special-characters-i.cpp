class Solution {
public:
    int numberOfSpecialChars(string word) {
        int freq[26] = {0};

        for (auto ch: word) {
            if (islower(ch)) {
                freq[ch - 'a']++;
            }
        }

        int ans = 0;
        for (auto ch: word) {
            if (isupper(ch) && freq[tolower(ch) - 'a'] > 0) {
                ans++;
                freq[tolower(ch) - 'a'] = 0;
            }
        }
        return ans;
    }
};