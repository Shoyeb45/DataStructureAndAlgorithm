class Solution {
public:
    int minRefuelStops(int target, int s, vector<vector<int>>& stations) {
        priority_queue<int> pq;

        int ans = 0;
        for (auto station: stations) {
            if (s >= station[0]) {
                pq.push(station[1]);
                continue;
            }



            while (!pq.empty() && s < station[0]) {
                s += pq.top();
                ans++;
                pq.pop();
            }
            // cout << s << "\n";
            if (pq.empty() && s < station[0]) {
                return -1;
            }
            pq.push(station[1]);
        }
        cout << s << "\n";
        while (!pq.empty() && s < target) {
            s += pq.top();
            ans++;
            pq.pop();
        }

        return (s >= target? ans : -1);
    }
};