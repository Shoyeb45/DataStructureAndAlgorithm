class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());

        priority_queue<int, vector<int>, greater<int>> free_rooms;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> et;


        for (int i = 0; i < n; i++) free_rooms.push(i);

        vector<int> ans(n);

        for (auto &x: meetings) {
            int s = x[0], e = x[1];

            // empty all the rooms which is less than s
            while (!et.empty()) {
                auto [end_time, room] = et.top();
                if (end_time <= s) {
                    et.pop();
                    free_rooms.push(room);
                } else {
                    break;
                }
            }
            
            if (!free_rooms.empty()) {
                int room = free_rooms.top();
                free_rooms.pop();
                ans[room]++;
                et.push(make_pair(e, room));
            } else {

                auto p = et.top();
                et.pop();
                ans[p.second]++;

                et.push(make_pair(e + (p.first - s), p.second));
            }
        }

        int j = -1;
        long long room_taken = LLONG_MIN;
        for (int i = 0; i < n; i++) {
            if (ans[i] > room_taken) {
                room_taken = ans[i];
                j = i;
            }
        }

        return j;
    }
};