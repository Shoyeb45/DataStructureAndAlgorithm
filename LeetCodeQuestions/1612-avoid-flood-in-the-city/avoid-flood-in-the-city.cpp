class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        unordered_map<int, int> mp;
        vector<int> ans(n), pos(n, INT_MAX);

        for (int i = n - 1; i >= 0; i--) {
            if (rains[i] != 0) {
                if (mp.find(rains[i]) != mp.end()) {
                    pos[i] = mp[rains[i]];
                }
                mp[rains[i]] = i;
            }
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        int randLake = 1;
        mp.clear();
    
        for (int i = 0; i < n; i++) {
            if (rains[i] > 0) {
                pq.push({pos[i], rains[i]});
                mp[rains[i]]++;
                if (mp[rains[i]] > 1) {
                    return {};
                }
                ans[i] = -1;
                randLake = rains[i];
            } else {
                if (!pq.empty()) {
                    auto [j, lake] = pq.top();
                    pq.pop();
                    // cout << lake << "\n";
                    ans[i] = lake;
                    mp[lake]--;
                } else {
                    ans[i] = randLake;
                }
            }
        }
        
        // while (!pq.empty()) {
        //     auto [x, lake] = pq.top();
        //     pq.pop();
        //     mp[lake]++;
        //     if (mp[lake] > 1) {
        //         return {};
        //     }
        // }

        return ans;
    }
};