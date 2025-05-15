class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int num1 = 0, num2 = 0, cnt1 = 0, cnt2 = 0;

        for (int x : nums) {
            if (x == num1) {
                cnt1++;
            } else if (x == num2) {
                cnt2++;
            } else if (cnt1 == 0) {
                num1 = x;
                cnt1++;
            } else if (cnt2 == 0) {
                num2 = x;
                cnt2++;
            } else {
                cnt2--;
                cnt1--;
            }
        }

        cnt1 = 0, cnt2 = 0;
        for (auto x : nums) {
            cnt1 += (x == num1);
            cnt2 += (x == num2);
        }

        vector<int> ans;

        if (cnt1 > nums.size() / 3) {
            ans.push_back(num1);
        }

        if (cnt2 > nums.size() / 3 && num2 != num1) {
            ans.push_back(num2);
        }

        return ans;
    }
};