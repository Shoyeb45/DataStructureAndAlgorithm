class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();

        reverse(digits.begin(), digits.end());

        // int to_plus = 1;
        int raise = 1;

        for (int i = 0; i < n; i++) {
            int new_val = digits[i] + raise;
            digits[i] = new_val % 10;
            raise = new_val / 10;
        }

        if (raise > 0) 
            digits.push_back(raise);

        reverse(digits.begin(), digits.end());
        return digits;
    }
};