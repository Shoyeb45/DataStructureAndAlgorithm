class Solution {
public:
    bool is_mergeable(vector<int> &i1, vector<int> &i2){
        return !(i1[1] < i2[0] || i2[1] < i1[0]);
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> new_interval = {intervals[0]};

        int n = intervals.size();

        auto is_mergeable = [&](vector<int> &i1, vector<int> &i2) -> bool {
            return !(i1[1] < i2[0] || i2[1] < i1[0]);
        };

        for (int i = 1; i < n; i++) {
            if (is_mergeable(intervals[i], new_interval.back())) {
                vector<int> n = {
                    min(intervals[i][0], new_interval.back()[0]),
                    max(intervals[i][1], new_interval.back()[1]),
                };
                new_interval.pop_back();
                new_interval.push_back(n);
            }   
            else {
                new_interval.push_back(intervals[i]);
            } 
        }
        return new_interval;
    }

    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> new_intervals;

        int i;
        for (i = 0; i < intervals.size(); i++) {
            if (intervals[i][0] >= newInterval[0]) {
                break;
            }
        }
        intervals.insert(intervals.begin() + i, newInterval);

        return merge(intervals);
    }
};