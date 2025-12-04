class Solution {
public:
    int countCollisions(string s) {
        int ans = 0;

        string tmp = "";
        int n = s.size();

        for (int i = 0; i < n; i++) { 
            if (s[i] == 'R' && (i + 1 < n && s[i + 1] == 'L')) {
                tmp += 'S';
                i++;
                ans += 2;
            } else {
                tmp += s[i];
            }
        } 
        s = "";
        cout << ans << "\n";
        cout << tmp << "\n";

        for (int i = 0; i < tmp.size(); i++) {
            if (tmp[i] == 'L' && i - 1 >= 0 && tmp[i - 1] == 'S') {
                int j = i;
                while (j < tmp.size() && tmp[j] == tmp[i]) {
                    j++;
                }

                for (int k = i; k < j; k++) tmp[k] = 'S';

                int cnt = j - i;
                i = j - 1;
                cout << cnt << " ";
                ans += cnt;
            }
        }

        cout << "\n" << tmp << "\n";
        n = tmp.size();

        for (int i = n - 1; i >= 0; i--) {
            if (tmp[i] == 'R' && (i + 1 < n && tmp[i + 1] == 'S')) {
                int j = i;

                while (j >= 0 && tmp[i] == tmp[j]) {
                    j--;
                }
                int cnt = i - j;
                for (int k = i; k > j; k--) tmp[k] = 'S';
                ans += cnt;
                i = j + 1;
            }
        }
        cout << tmp << "\n";
        return ans;
    }
};