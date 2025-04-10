#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);


class Solution {
public:
    void genParanthesis(string s, int n, vector<string> &ans, int openingBrackets = 0, int closingBrackets = 0) {
        if (s.size() == 2 * n) {
        // cout << s << "\n";
            ans.push_back(s);
            return;
        }

        if (openingBrackets + 1 <= n) {
            genParanthesis(s + '(', n, ans, openingBrackets + 1, closingBrackets);
        }
        if (closingBrackets + 1 <= openingBrackets) {
            genParanthesis(s + ')', n, ans, openingBrackets, closingBrackets + 1);
        }

    }

    vector<string> generateParenthesis(int n) {
        NFS
        vector<string> ans;
        genParanthesis("", n, ans);
        return ans;
    }
};