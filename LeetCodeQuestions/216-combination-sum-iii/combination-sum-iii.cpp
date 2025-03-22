class Solution {
public:
    void f(int k, int sum, vector<set<int>> &ans, set<int> &temp, int start = 1) {
        if (sum == 0 && k == 0) { 
            ans.push_back(temp);
            return;
        }

        for (int i = start; i <= 9; i++) {
            if (k - 1 >= 0 && sum - i >= 0 && temp.find(i) == temp.end()) {
                temp.insert(i);
                f(k - 1, sum - i, ans, temp, i + 1);
        temp.erase(i);
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        set<int> a;
        vector<set<int>> ans;
        f(k, n, ans, a);

        vector<vector<int>> d;
        for (auto x : ans) {
            d.push_back(vector<int> (x.begin(), x.end()));
        }

        return d;
    }
};