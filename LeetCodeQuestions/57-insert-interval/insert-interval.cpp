class Solution {
public:

    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> new_intervals;

        auto is_mergeable = [&](vector<int> &i1, vector<int> &i2) -> bool {
            return !(i1[1] < i2[0] || i2[1] < i1[0]);
        };
        int n = intervals.size();

        int i = 0; 

        for (; i < n; i++) {
            if (is_mergeable(newInterval, intervals[i])) {
                newInterval = {
                    min(newInterval[0], intervals[i][0]),
                    max(newInterval[1], intervals[i][1]),
                };
            }
            else if (intervals[i][0] < newInterval[0]) {
                new_intervals.push_back(intervals[i]);
            }
            else {
                new_intervals.push_back(newInterval);
                while (i < n) {
                    new_intervals.push_back(intervals[i++]);
                }
                return new_intervals;
            }
        }    


        new_intervals.push_back(newInterval);

        return new_intervals;
    }
};