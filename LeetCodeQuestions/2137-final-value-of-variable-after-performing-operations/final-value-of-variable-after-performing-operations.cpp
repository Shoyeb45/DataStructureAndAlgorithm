class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int ans = 0;
        for (auto x: operations) {
            if (x[0] == 'X') {
                ans = x[1] == '+' ? ans + 1: ans - 1;
            } else {
                ans = x[0] == '+' ? ans + 1: ans - 1;
            }
        }
        return ans;
    }
};