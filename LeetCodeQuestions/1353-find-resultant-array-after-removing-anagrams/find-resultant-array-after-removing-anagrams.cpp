class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        if (words.size() == 1) {
            return words;
        }
        vector<string> a = words;
        for (auto &x: a) {
            sort(x.begin(), x.end());
        }
        int n = a.size();
        vector<string> ans;
        for (int i = 0; i < n; i++) {
            if (i + 1 < n && a[i] == a[i + 1]) {
                int j = i;
                while (j < n && a[j] == a[i]) {
                    j++;
                }
                ans.push_back(words[i]);
                i = j - 1;
            } else {
                if (i == n - 1 && a[i] == a[i - 1]) {
                    continue;
                }
                ans.push_back(words[i]);
            }
        }
        return ans;
    }
};