class Solution {
public:
    void genUniqueSubsets(map<int, int> &mp, std::map<int, int>::iterator it, vector<int> &a, vector<vector<int>> &ans) {
        if (it == mp.end()) {
            ans.push_back(a);
            return;
        }

        int val = it -> first;
        int freq = it -> second;
        genUniqueSubsets(mp, next(it), a, ans);

        for (int i = 0; i < freq; i++) {
            a.push_back(val);
            genUniqueSubsets(mp, next(it), a, ans);
        }

        for (int i = 0; i < freq; i++) {
            a.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> a;
        vector<vector<int>> ans;
        map<int, int> mp;
        for (auto x : nums) {
            mp[x]++;
        }

        genUniqueSubsets(mp, mp.begin(), a, ans);
        return ans;
    }
};