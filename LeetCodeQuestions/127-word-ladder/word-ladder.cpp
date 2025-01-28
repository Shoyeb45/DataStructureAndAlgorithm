class Solution {
    void print(queue<pair<string, int>> q) {
        while (!q.empty()) {
            cout << q.front().first << " " << q.front().second;
            q.pop();
        }
    }
public:
    int ladderLength(string beginWord, string endWord, vector<string>& words) {
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        unordered_map<string, int> mp;

        set<string> st(words.begin(), words.end());

        while (!q.empty()) {
            string word = q.front().first;
            int step = q.front().second;
            q.pop();
            // print(q);

            // cout << "word : " << word << "\n";
            if (word == endWord) {
                return step;
            }

            for (int i = 0; i < word.size(); i++) {
                string temp = word;

                for (int j = 0; j < 26; j++) {

                    if ((int)(j + 'a') != (int)temp[i]) {
                        temp[i] = (char)(j + 'a');
                        if (st.find(temp) != st.end() && mp.find(temp) == mp.end()) {
                            q.push({temp, step + 1});
                            mp[temp]++;
                        }
                        // temp = word;
                    }

                }
            }
        }
        return 0;
    }
};