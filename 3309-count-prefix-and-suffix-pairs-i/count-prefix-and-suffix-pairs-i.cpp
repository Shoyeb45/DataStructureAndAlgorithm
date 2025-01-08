class Solution {
    bool isPrefix(string &str1, string &str2) {
        if (str2.size() < str1.size()) {
            return false;
        }
        // cout << str1 << " " << str2 << "\n";
        int i = 0, j = 0;

        while (i < str1.size() && j < str2.size()) {
            if (str1[i] != str2[j]) {
                break;
            }
            i++, j++;
        }
        return i >= str1.size();
    }

    bool isPrefixAndSuffix(string str1, string str2) {
        bool ans = isPrefix(str1, str2);
        reverse(str2.begin(), str2.end());
        reverse(str1.begin(), str1.end());
        return ans && isPrefix(str1, str2);
    }
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int ans = 0;
        for (int i = 0; i < words.size(); i++) {
            for (int j = i + 1; j < words.size(); j++) {
                ans += isPrefixAndSuffix(words[i], words[j]);
                // cout << isPrefixAndSuffix(words[i], words[j]) << "\n";
            }
        }
        return ans;
    }
};