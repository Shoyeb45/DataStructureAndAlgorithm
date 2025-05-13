class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int _xor = 0;
        for (auto x : nums) {
            _xor ^= x; 
        }

        int mask = 0;
        for (int i = 0; i < 32; i++) {
            mask = (1 << i);
            if (mask & _xor) {
                mask = (1 << i);
                break;
            }
        }

        int numSet = 0, numUnset = 0;
        for (auto x: nums) {
            if ((mask & x)) {
                numSet ^= x;
                continue;
            }
            numUnset ^= x;
        }   

        return {numSet, numUnset};
    }
};