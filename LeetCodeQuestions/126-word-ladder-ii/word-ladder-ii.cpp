class Solution {
public:
    bool is_adjacent(string& s, string& t) {
        int count = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != t[i]) {
                count++;
            }
        }
        return count == 1;
    }

    vector<int> min_dist(int src, int dest, vector<vector<int>>& adj, int n) {
        queue<int> q;
        q.push(src);
        vector<int> dist(n + 1, INT_MAX);
        dist[src] = 0;

        vector<bool> vis(n + 1, false);
        vis[src] = true;
        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v : adj[u]) {
                if (!vis[v]) {
                    vis[v] = true;
                    q.push(v);
                    if (dist[u] + 1 < dist[v]) {
                        dist[v] = dist[u] + 1;
                    }
                }
            }
        }
        return dist;
    }

    vector<vector<string>> findLadders(string start, string endWord,
                                       vector<string>& wordList) {
        // no end word found
        if (std::find(wordList.begin(), wordList.end(), endWord) ==
            wordList.end()) {
            return {};
        }
        int n = wordList.size();
        vector<vector<int>> adj(n + 1);

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (is_adjacent(wordList[i], wordList[j])) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (is_adjacent(wordList[i], start)) {
                adj[i].push_back(n);
                adj[n].push_back(i);
            }
        }

        int dest = -1;
        for (int i = 0; i < n; i++) {
            if (wordList[i] == endWord) {
                dest = i;
                break;
            }
        }

        auto distance = min_dist(n, dest, adj, n);

        vector<vector<string>> ans;

        vector<bool> vis(n + 1, false);

        std::function<void(int, vector<string>&)> dfs =
            [&](int u, vector<string>& temp) {
                if (u == n) { // reached start
                    vector<string> a = temp;
                    reverse(a.begin(), a.end());
                    ans.push_back(a);
                    return;
                }

                for (int v : adj[u]) {
                    if (distance[u] - 1 == distance[v]) {
                        if (v == n) {
                            temp.push_back(start);
                            dfs(v, temp);
                            temp.pop_back();
                        } else {
                            temp.push_back(wordList[v]);
                            dfs(v, temp);
                            temp.pop_back();
                        }
                    }
                }
            };
        vector<string> temp = {endWord};
        dfs(dest, temp);
        vis[n] = true;
        return ans;
    }
};