class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        vector<int> idxs;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                idxs.push_back(i);
            }
        }
        
        for (int i = 0; i < (int) idxs.size() - 1; i++) {
            cout << idxs[i] << " " << idxs[i + 1] << "\n";
            if (abs(-idxs[i] + idxs[i + 1] - 1) < k) {
                return false;
            }
        }
        return true;
    }
};