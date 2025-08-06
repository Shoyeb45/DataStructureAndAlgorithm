class TrieNode {
public:
    map<char, TrieNode*> child;
    bool isEnd;
    TrieNode() {
        isEnd = false;
    }
};

void addWord(TrieNode* root, string& word) {
    TrieNode* node = root;
    for (int i = 0; i < word.size(); i++) {
        auto& mp = node -> child;

        if (mp.find(word[i]) == mp.end()) {
            mp[word[i]] = new TrieNode();
        }
        node = mp[word[i]];
    }

    node -> isEnd = true;
}

bool search(TrieNode* root, string& word) {
    TrieNode* node = root;
    for (int i = 0; i < word.size(); i++) {
        auto& mp = node -> child;

        if (mp.find(word[i]) == mp.end()) {
            return false;
        }
        node = mp[word[i]];
    }

    return node -> isEnd;
}

class Solution {
public:
    vector<string> ans;
    TrieNode* root = new TrieNode(); 

    void f(int i, string& s, string a) {
        int n = s.size();
        if (i == n) {
            // cout << a << "\n";
            ans.push_back(a);
            return;
        }

        string temp = "";
        // int ans = 0;
        for (int j = i; j < n; j++) {
            temp += s[j];
            if (search(root, temp)) {
                // cout << temp << "\n";
                string ns = "";
                if (a == "") {
                    ns += temp;
                } else {
                    ns += a + " " + temp;
                }
                f(j + 1, s, ns);
            }
        }

        return;
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for (string word: wordDict) {
            addWord(root, word);
        }
        f(0, s, "");
        return ans;
    }
};