class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> dp = {{1}};


        for (int i = 1; i <= rowIndex; i++) {
            vector<int> temp = {1};
            for (int j = 0; j < dp[i - 1].size() - 1; j++) {
                temp.push_back(dp[i - 1][j + 1] + dp[i - 1][j]);
            }
            temp.push_back(1);
            dp.push_back(temp);
        }

        return dp[rowIndex];
    }
};