class Solution {
public:
    int dp[2001][2001];
    vector<int> prefStar;
    string s, p;
    int f(int i, int j) {
        if (i >= s.size() && j >= p.size()) {
            return 1;
        }
        else if (j >= p.size()) {
            return 0;
        }
        else if (i >= s.size()) {
            return (prefStar[(int)p.size()] - prefStar[j]) == (int)p.size() - j;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        if (p[j] == '*') {
            return dp[i][j] = f(i, j + 1) || f(i + 1, j);
        }

        if ((s[i] == p[j] || p[j] == '?')) {
            return dp[i][j] = f(i + 1, j + 1);
        }

        return 0;
    }

    bool isMatch(string s, string p) {
        memset(dp, -1, sizeof(dp));

        this -> s = s, this -> p = p;

        prefStar.assign(p.size() + 1, 0);

        for (int i = 1; i <= p.size(); i++) {
            prefStar[i] = prefStar[i - 1] + (p[i - 1] == '*');
        } 
        for (int i = 1; i <= p.size(); i++) {
            cout << prefStar[i] << " ";
        }
        cout <<"\n";
        return f(0, 0);
    }
};