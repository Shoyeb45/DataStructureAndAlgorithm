class Solution {
public:
    int dp[601][101][101];
    vector<pair<int, int>> a;
    int f(int idx, int ones, int zeroes) {
        if (idx >= a.size()) {
            return 0;
        }
        if (ones == 0 && zeroes == 0) {
            return 0;    
        }
        if (dp[idx][ones][zeroes] != -1) {
            return dp[idx][ones][zeroes];
        }
        
        int not_pick = f(idx + 1, ones, zeroes);
        int pick = INT_MIN;
        if (ones - a[idx].first >= 0 && zeroes - a[idx].second >= 0) {
            pick = 1 + f(idx + 1, ones - a[idx].first, zeroes - a[idx].second);
        }
        return dp[idx][ones][zeroes] = max(not_pick, pick);
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        memset(dp, -1, sizeof dp);
        for (auto& s: strs) {
            int ones = count(s.begin(), s.end(), '1');
            a.push_back(make_pair(ones, s.size() - ones));
        }        

        return f(0, n, m);
    }
};