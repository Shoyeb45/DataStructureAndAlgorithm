class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        
        priority_queue<int, vector<int>, greater<int>> pq;

        sort(intervals.begin(), intervals.end());
        // pq.push(intervals[0][1]);

        for (int i = 0; i < intervals.size(); i++) {
            if (!pq.empty() && intervals[i][0] > pq.top()) {
                pq.pop();
            } 
            
            pq.push(intervals[i][1]);

        }
        return pq.size();
    }
};