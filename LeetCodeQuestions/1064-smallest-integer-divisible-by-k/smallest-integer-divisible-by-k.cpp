class Solution {
public:
    int smallestRepunitDivByK(int k) {
        
        int n = 1;
        int num = 0;
        while (true) {
            num = (num * 10 + 1) % k;
            if (num == 0) return n;
            n++;
            if (n > 100000) break;
        }
        return -1;
    }
};