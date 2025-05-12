class Solution {
public:
    void find(map<int, int> &mp, vector<int> &temp, vector<vector<int>> &ans) {
        if (mp.empty()) {
            ans.push_back(temp);
        }

        for (auto x: mp) {
            auto n_mp = mp;
            temp.push_back(x.first);
            n_mp[x.first]--;
            if (n_mp[x.first] == 0) {
                n_mp.erase(x.first);
            }
            find(n_mp, temp, ans);
            temp.pop_back();
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
            find(mp, temp, ans);
        }
        return ans;
    }
};