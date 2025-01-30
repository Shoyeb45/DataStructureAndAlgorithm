class Solution {
public:
    void f(vector<int> &a, vector<vector<int>> &ans, vector<int> &temp, int target, int index = 0) {
        if (target == 0) {
            ans.push_back(temp);
            return;
        }
        if (index >= a.size() || a[index] > target) {
            return;
        }


        int freq = 0;
        int val = a[index];

        for (; index < a.size(); index++) {
            if (a[index] != val) {
                break;
            }
            else {
                freq++;
            }
        }
        int times = 0;
        // cout << index << "\n";

        f(a, ans, temp, target, index);

        for (int i = 1; i <= freq; i++) {
            if (i * val <= target) {
                temp.push_back(val);
                times++;
                f(a, ans, temp, target - i * val, index);
            }
            else {
                break;
            }
        }

        while (times--) {
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> a;
        f(candidates, ans, a, target);
        return ans;
    }
};