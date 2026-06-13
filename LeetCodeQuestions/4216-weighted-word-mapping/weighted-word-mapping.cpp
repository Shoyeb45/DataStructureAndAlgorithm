class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans = "";

        for (auto &x: words) {
            int tot_weights = 0;
            for (auto &ch: x) {
                tot_weights += weights[ch - 'a'];
            }
            ans += (char) ((25 - tot_weights % 26) + 'a');
        }

        return ans;
    }
};