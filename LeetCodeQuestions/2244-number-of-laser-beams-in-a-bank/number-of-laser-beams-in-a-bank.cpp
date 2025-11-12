#define range(x) (x).begin(), (x).end()
class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int ans = 0;
        int n = bank.size(), m = bank[0].size();

        auto cnt_one = [&](int i) -> int {
            return count(range(bank[i]), '1');
        };
        int i = 0;
        int last_cnt = 0;
        while (i < n && last_cnt != 0) {
            last_cnt = cnt_one(i);
            i++;
        }

        for (; i < n; i++) {
            int cnt = cnt_one(i);
            if (cnt != 0) {
                ans += cnt * last_cnt;
                last_cnt = cnt;
            }
        }
        return ans;
    }
};