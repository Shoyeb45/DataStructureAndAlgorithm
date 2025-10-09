using ll = long long;

class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n = skill.size(), m = mana.size();
        partial_sum(skill.begin(), skill.end(), skill.begin());

        ll skill0 = skill[0];
        ll start = 0;
        for (int i = 1; i < m; i++) {
            ll prev = mana[i - 1], curr = mana[i];

            ll mx = 1LL * skill0 * prev;
            for (int j = 1; j < n; j++) {
                mx = max(mx, 1LL * skill[j] * prev - 1LL * skill[j - 1] * curr);
            }
            start += mx;
        }   

        return start + 1LL * skill.back() * mana[m - 1];
    }
};