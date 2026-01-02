class Solution {
public:
    int repeatedNTimes(vector<int>& a) {
        int n = a.size();

        // I have n + 1 unique numbers, and one number repeats n times
        // 5,1,5,2,5,3,5,4

        for (int i = 0; i < n; i++) {
            bool ans = false;
            for (int k = 1; k < 4; k++) {
                if (i + k >= n) break;
                ans |= a[i] == a[i + k];
            }
            if (ans)
                return a[i];
        }

        return -1;
    }
};



// n = 2
// 1 2 3 2