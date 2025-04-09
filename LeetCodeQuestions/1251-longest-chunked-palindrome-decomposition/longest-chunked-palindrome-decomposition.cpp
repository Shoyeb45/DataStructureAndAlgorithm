class Solution {
public:
    int f(string text) {
        int n = text.size();

        for (int i = 0; i < n / 2; i++) {
            if (text.substr(0, i + 1) == text.substr(n - i - 1, i + 1)) {
                return 2 + f(text.substr(i + 1, n - 2 * (i + 1)));
            }
        }

        return (n == 0? 0: 1);
    }

    int longestDecomposition(string text) {
        return f(text);
    }
};