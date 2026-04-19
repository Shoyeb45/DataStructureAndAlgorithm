class Solution {
public:
    int maxDistance(vector<int>& a, vector<int>& b) {
        int i = 0, j = 0;
        int ans = 0;

        while (i < a.size() && j < b.size()) {
            if (a[i] > b[j]) {
                i++;
            }
            else {
                ans = max (ans, j - i);
                j++;
            }
        }  
        return ans;
    }
};