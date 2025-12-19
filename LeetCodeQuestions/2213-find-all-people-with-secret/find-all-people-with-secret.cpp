// 2, 3, 0

// All of the above people contains secret
// now I have list at time x,
// [7 , 4]
// [1 , 2]
// [4 , 3] 
// It's always optimal to process those meetings first which already have the secrets

class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& m, int f) {
        // we need to process those meetings first which already have the secrets

        map<int, vector<pair<int, int>>> mp;
        for (auto &x: m) {
            mp[x[2]].push_back(make_pair(x[0], x[1]));
        }

        vector<bool> is_s(n);
        is_s[0] = is_s[f] = 1;

        for (auto &x: mp) {
            vector<pair<int, int>> meetings = x.second;
            unordered_map<int, vector<int>> adj;

            queue<int> q;
            unordered_set<int> st;

            for (auto x: meetings) {
                if (is_s[x.first]) st.insert(x.first);
                if (is_s[x.second]) st.insert(x.second);

                adj[x.first].push_back(x.second);
                adj[x.second].push_back(x.first);
            }

            for (int x: st) q.push(x);

            while (!q.empty()) {
                int u = q.front();
                q.pop();

                for (auto &v: adj[u]) {
                    if (!is_s[v]) {
                        is_s[v] = 1;
                        q.push(v);
                    }
                }
            }
        }

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (is_s[i]) ans.push_back(i);
        }

        return ans;
    }
};