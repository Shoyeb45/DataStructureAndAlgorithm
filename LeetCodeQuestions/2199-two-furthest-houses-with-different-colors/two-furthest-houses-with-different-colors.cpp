class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int ans = 0;

        for (int i = 1; i < colors.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (colors[j] != colors[i]) { 
                    ans = max(ans, abs(j - i));
                    break;
                }
            }
        }
        return ans;
    }
};