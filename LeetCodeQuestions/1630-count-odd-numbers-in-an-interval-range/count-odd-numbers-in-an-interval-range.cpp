class Solution {
public:
    int countOdds(int low, int high) {
        int _low = low -  (low == 0? 0: 1);

        int nums = high / 2 - (_low) / 2 + (low == 0);

        return high - low + 1 - nums;
    }
};

// odd odd
// even even
// odd even
// even odd