using ll = long long;

class SGTree {
    int n;
    vector<int> tree;
    std::function<int(int, int)> fn;
    int edge_element;

public:
    SGTree(int n, std::function<int(int, int)> fn, int edge_element) {
        this->n = n;
        tree.resize(4 * n + 1);
        this->fn = fn;
        this->edge_element = edge_element;
    }

    void build(vector<int> &nums) {
        this->build_sg(nums, 0, this->n - 1, 0);
    }

    int get(int l, int r) {
        return get_element(0, n - 1, 0, l, r);
    }
private:
    void build_sg(vector<int> &a, int l, int r, int idx) {
        if (l == r) {
            tree[idx] = a[l];
            return;
        }
        int mx = (l + r) / 2;

        int i = 2 * idx + 1;
        build_sg(a, l, mx, i);
        build_sg(a, mx + 1, r, i + 1);

        tree[idx] = this->fn(tree[i], tree[i + 1]);
        return;
    }

    int get_element(int l_t, int r_t, int idx, int l, int r) {
        if (l <= l_t && r_t <= r) {
            return tree[idx];
        } else if (r_t < l || r < l_t) {
            return this->edge_element;
        } else {
            int mx = (l_t + r_t) / 2;

            return this->fn(
                get_element(l_t, mx, 2 * idx + 1, l , r),
                get_element(mx + 1, r_t, 2 * idx + 2, l , r)
            );
        }
    }
};

class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        SGTree sg_mx(nums.size(), [](int a, int b) -> int {
            return max(a, b);
        }, INT_MIN);
        sg_mx.build(nums);

        SGTree sg_mn(nums.size(), [](int a, int b) -> int {
            return min(a, b);
        }, INT_MAX);
        sg_mn.build(nums);

        int n = nums.size();
        priority_queue<pair<int, pair<int, int>>> pq;

        for (int i = 0; i < n; i++) {
            int mn = sg_mn.get(i, n - 1);
            int mx = sg_mx.get(i, n - 1);
            // cout << i << " " << n - 1 << " => " << mx << ", " << mn << "\n";
            pq.push(make_pair(mx - mn, make_pair(i, n - 1)));    
        }

        ll ans = 0;
        for (int _k = 0; _k < k; _k++) {
            auto [val, idx] = pq.top();
            pq.pop();
            ans += val;

            int l = idx.first, r = idx.second;
            // cout << l << " " << r << "\n";
            if (r > l) {
                int mx = sg_mx.get(l, r - 1);
                int mn = sg_mn.get(l, r - 1);
                // cout << l << " " << r - 1 << " => " << mx << ", " << mn << "\n";
                pq.push(make_pair(
                    mx - mn,
                    make_pair(l, r - 1)
                ));
            }
        }


        // while (k--) {
        //     ans += pq.top().first;
        //     cout << pq.top().first << " ";
        //     pq.pop();
        // }
        return ans;
    }
};