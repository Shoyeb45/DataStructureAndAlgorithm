#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
#pragma GCC target ("avx2")
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")

class Solution {
public:

    vector<string> split_by_space(string& s) {
        NFS
        int n = s.size();
        vector<string> li;
        string tmp = "";

        for (int i = 0; i < n; i++) {
            if (s[i] == ' ') {
                li.push_back(tmp);
                tmp = "";
                continue;
            }
            tmp += s[i];
        }
        if (tmp != "")
            li.push_back(tmp);
        return li;
    }
    
    vector<int> countMentions(int n, vector<vector<string>>& events) {
        vector<set<int>> pref(n);
        for (auto& x: events) {
            if (x[0] == "OFFLINE") {
                int t = stoi(x[1]);
                int id = stoi(x[2]);
                pref[id].insert(t);
            }
        }

        auto check = [&](int t, int id) -> bool {
            for (auto& x: pref[id]) {
                if (t >= x && t <= x + 59)
                    return false;
            }
            return true;
        };

        vector<int> ans(n);
        for (auto& x: events) {
            if (x[0] == "MESSAGE") {
                int t = stoi(x[1]);
                if (x[2] == "ALL") {
                    for (int i = 0; i < n; i++)
                        ans[i]++;
                } else if (x[2] == "HERE") {
                    for (int i = 0; i < n; i++)
                        if (check(t, i))
                            ans[i]++;
                } else {
                    vector<string> tmp = split_by_space(x[2]);
                    for (auto& x: tmp) {
                        int id = stoi(x.substr(2));
                        ans[id]++;
                    }
                }
            }
        }
        
        return ans;
    }
};