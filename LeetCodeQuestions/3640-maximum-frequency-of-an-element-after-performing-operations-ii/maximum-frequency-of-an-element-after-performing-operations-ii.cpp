class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int ope) {
        map<int, int> mp;   
        unordered_map<int, int> freq; 
        for (auto x : nums) {
            freq[x]++;
            mp[x - k]++;
            mp[x] += 0;
            mp[x + k + 1]--;
        }

        int cnt = 0, ans = INT_MIN;
        for (auto it : mp) {
            cnt += it.second;
            int f;

            if (cnt > ope) {
                f = min(freq[it.first] + ope, cnt);
            }
            else {
                f = cnt;
            }
           
            ans = max(ans, f);
        }

        return ans;
    }
};