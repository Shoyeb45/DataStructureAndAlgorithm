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
        

        f(a, ans, temp, target, index + 1);
        // cout << target << " " << a[index] << " " << (target / a[index]) << "\n";
        for (int i = 1; i <= (target / a[index]); i++) {
            // cout << index << "\n";
            temp.push_back(a[index]);
            f(a, ans, temp, target - i * a[index], index + 1);
        }

        for (int i = 1; i <= (target / a[index]); i++) {
            temp.pop_back();
        }
    } 

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        f(candidates, ans, temp, target);
        return ans;
    }
};