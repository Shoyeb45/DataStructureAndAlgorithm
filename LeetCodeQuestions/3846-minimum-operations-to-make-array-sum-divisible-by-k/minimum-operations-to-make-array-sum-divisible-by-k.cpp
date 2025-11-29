class Solution {
public:
    int minOperations(vector<int>& a, int k) {
        int sum = 0;
        for (auto& x: a) sum += x;

        if (sum % k == 0) return 0;

        if (sum > k) return sum - (sum / k) * k;
        return sum;
    }
};