class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // Moore's Voting Algorithm

        int count = 0, num = 0;

        for (auto x : nums) {
            if (count == 0) {
                num = x;
            }

            if (x == num) {
                count++;
            }
            else {
                count--;
            }
        }

        count = 0;
        for (auto x : nums) {
            count += (x == num);
        }

        if (count >= nums.size() / 2) {
            return num;
        }
        return -1;
    }
};