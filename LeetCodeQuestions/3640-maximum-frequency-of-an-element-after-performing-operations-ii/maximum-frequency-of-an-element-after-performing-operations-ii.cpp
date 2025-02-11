
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        map<int, int> mp;
        map<int, int> hmp;

        for (int i = 0; i < nums.size(); i++) {
            int start = nums[i] - k;
            int end = nums[i] + k;
            hmp[nums[i]]++; 
            mp[start]++;
            mp[end + 1]--; 
            mp[nums[i]] += 0;
        }

        int ans = 0, count = 0;
        for (auto it = mp.begin(); it != mp.end(); it++) {
            count += it->second;
            if (count > numOperations) {
                int freq = min(hmp[it->first] + numOperations, count);
                ans = max(ans, freq);
            } else {
                ans = max(ans, count);
            }
        }
        return ans;
    }
};