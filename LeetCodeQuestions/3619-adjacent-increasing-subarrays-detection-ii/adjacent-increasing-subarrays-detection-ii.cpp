class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int prev = 0;
        vector<int> a;
        for (int i = 0; i < n; i++) {
            int curr;
            if (i + 1 < n && nums[i + 1] > nums[i]) {
                cout << i << " ";
                int j = i;
                while (j + 1 < n && nums[j + 1] > nums[j]) {
                    j++;
                }
                curr = j - i + 1;
                cout << j << "\n";
                i = j;
            } else {
                curr = 1;
            }
            ans = max(ans, min(curr, prev));
            ans = max(ans, curr / 2);
            prev = curr;
            a.push_back(curr);
        }  
       
        return ans;
    }
};