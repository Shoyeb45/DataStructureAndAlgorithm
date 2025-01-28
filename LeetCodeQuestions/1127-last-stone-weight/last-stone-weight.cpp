class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(), stones.end());

        while (pq.size() >= 2) {
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();
            if (x != y) {
                pq.push(x - y);
            }
            else if (pq.size() == 0) {
                pq.push(0);
            }
        }
        // cout << pq.size();
        return pq.top();
    }
};