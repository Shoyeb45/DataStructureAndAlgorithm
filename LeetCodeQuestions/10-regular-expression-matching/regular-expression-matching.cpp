class Solution {
string s, p;
public:
    int f(int i, int j) {
        if (i >= s.size() && j >= p.size()) {
            return 1;
        }
        else if (j >= p.size()) {
            return 0;
        }

        bool match = (i < s.size() && (s[i] == p[j] || p[j] == '.'));

        if (j + 1 < p.size() && p[j + 1] == '*') {
            return f(i, j + 2) || (match? f(i + 1, j): false);
        } 
        else if (match) {
            return f(i + 1, j + 1);
        }
        return 0;
    }
    bool isMatch(string s, string p) {
        this -> s = s, this -> p = p;
        return f(0, 0);
    }
};