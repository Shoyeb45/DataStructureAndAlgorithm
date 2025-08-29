class RangeFreqQuery {
public:
    vector<vector<int>> tree;
    int n;
    RangeFreqQuery(vector<int>& arr) {
        n = arr.size();
        tree.resize((4 * n) + 1);
        build(0, n - 1, 0, arr);
    }
    
    int query(int left, int right, int value) {
        return get_freq(0, n - 1, 0, left, right, value);
    }

    int get_freq(int s_l, int s_r, int tree_index, int q_l, int q_r, int val) {
        if (q_l <= s_l && s_r <= q_r) {
            return find_freq(tree[tree_index], val);
        } else if (s_r < q_l || q_r < s_l) {
            return 0;
        } 
        int mid = (s_l + s_r) / 2;
        int left = (2 * tree_index) + 1, right = (2 * tree_index) + 2;

        int left_freq = get_freq(s_l, mid, left, q_l, q_r, val);
        int right_freq = get_freq(mid + 1, s_r, right, q_l, q_r, val);
        return left_freq + right_freq;
    }

    void build(int l, int r, int tree_index, vector<int> &a) {
        if (l == r) {
            tree[tree_index].push_back(a[l]);
            return;
        }

        int mid = (l + r) / 2;
        int left = (2 * tree_index) + 1, right = (2 * tree_index) + 2;
        build(l, mid, left, a);
        build(mid + 1, r, right, a);
        tree[tree_index] = merge(tree[left], tree[right]);
    }


    int find_freq(vector<int> &a, int val) {
        auto lb = lower_bound(a.begin(), a.end(), val);
        auto ub = upper_bound(a.begin(), a.end(), val);
        return ub - lb;
    }

    vector<int> merge(vector<int> &a, vector<int> &b) {
        int i = 0, j = 0;
        vector<int> ans;
        while (i < a.size() && j < b.size()) {
            if (a[i] < b[j]) {
                ans.push_back(a[i++]);
            } else {
                ans.push_back(b[j++]);
            }
        }

        while (i < a.size()) {
            ans.push_back(a[i++]);
        }

        while (j < b.size()) {
            ans.push_back(b[j++]);
        }
        return ans;
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */