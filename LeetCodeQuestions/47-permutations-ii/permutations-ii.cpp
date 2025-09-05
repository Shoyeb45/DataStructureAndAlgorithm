class Solution {
public:
    void f(vector<int> &temp, int n, vector<vector<int>> &ans, map<int, int> &mp) {
        if (temp.size() == n) {
            ans.push_back(temp);
            return;
        }

        for (auto it: mp) {
            if (it.second != 0) {
                mp[it.first]--;
                temp.push_back(it.first);
                f(temp, n, ans, mp);
                mp[it.first]++;
                temp.pop_back();

            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& a) {
        vector<vector<int>> ans;
        {
            map<int, int>  mp;
            for (auto x : a) {
                mp[x]++;
            }
            vector<int> temp;
            f(temp, (int) a.size(), ans, mp);
        }
        return ans;
    }
};