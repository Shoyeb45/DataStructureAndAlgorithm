using ll = long long;

class Solution {
public:
    vector<long long> findXSum(vector<int>& a, int k, int x) {
        int n = a.size();
        unordered_map<int, int> freq;
        auto cmp = [&](int a, int b) {
            if (freq[a] != freq[b])
                return freq[a] < freq[b];
            return a < b;
        };
        set<int, decltype(cmp)> top_x(cmp), rest(cmp);
        ll sum_top = 0;
        vector<ll> ans(n - k + 1);

        auto rebalance = [&]() -> void {
            while (top_x.size() < min(x, (int)freq.size()) && !rest.empty()) {
                int best = *rest.rbegin();
                rest.erase(best);
                top_x.insert(best);
                sum_top += 1LL * freq[best] * best;
            }

            while (top_x.size() > x) {
                int worst = *top_x.begin();
                top_x.erase(worst);
                rest.insert(worst);
                sum_top -= 1LL * freq[worst] * worst;
            }
            while (!top_x.empty() && !rest.empty()) {
                int worst_top = *top_x.begin();
                int best_rest = *rest.rbegin();

                if (
                    (freq[best_rest] > freq[worst_top]) ||
                    (freq[best_rest] == freq[worst_top] && best_rest > worst_top)
                ) {
                    top_x.erase(worst_top);
                    rest.erase(best_rest);
                    top_x.insert(best_rest);
                    rest.insert(worst_top);
                    sum_top += 1LL * best_rest * freq[best_rest] - 1LL * worst_top * freq[worst_top];
                } else {
                    break;
                }
            }
        };

        auto remove_ele = [&](int ele) -> void {
            if (top_x.find(ele) != top_x.end()) {
                top_x.erase(ele);
                sum_top -= 1LL * ele * freq[ele];
            }
            else if (rest.find(ele) != rest.end()) {
                rest.erase(ele);
            }
        };

        for (int i = 0; i < n; i++) {
            remove_ele(a[i]);
            freq[a[i]]++;
            rest.insert(a[i]);
            rebalance();

            if (i >= k) {
                int u = a[i - k];
                remove_ele(u);
                if (freq[u] == 1) {
                    freq.erase(u);
                } else {
                    freq[u]--;
                    rest.insert(u);
                }
                rebalance();
            } 
            if (i >= k - 1) {
                ans[i - k + 1] = sum_top;
            }
        }

        return ans;
    }
};