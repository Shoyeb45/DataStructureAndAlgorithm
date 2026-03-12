class DSU {
public:
    vector<int> parent, height;
    DSU(int n) {
        parent.resize(n);
        height.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    } 

    int get(int x) {
        if (parent[x] == x) {
            return x;
        }
        return parent[x] = get(parent[x]);
    }

    void merge(int x, int y) {
        int p_x = get(x), p_y = get(y);
        // let's maintain height[p_x] > height[p_y]
        if (height[p_x] < height[p_y]) {
            swap(p_x, p_y);
        }

        // merge y into x
        parent[p_y] = p_x;
        height[p_x] = max(height[p_y] + 1, height[p_x]); 
    }
};

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        int arr[26] = {0};
        
        for (auto &eq: equations) {
            int x = eq[0] - 'a';
            int y = eq[3] - 'a';
            arr[x] = arr[y] = 1;
        }
        int n = 0;
        for (int i = 0; i < 26; i++) {
            if (arr[i]) {
                n = max(n, i + 1);
            }
        }
        cout << n << " ";
        DSU dsu(n);

        for (auto &eq: equations) {
            int x = eq[0] - 'a';
            int y = eq[3] - 'a';
            bool eql = eq[1] == '=';

            if (eql) {
                dsu.merge(x, y);
            } 
        }

        for (auto &eq: equations) {
            int x = eq[0] - 'a';
            int y = eq[3] - 'a';
            bool eql = eq[1] == '=';

            if (!eql) {
                int a = dsu.get(x);
                int b = dsu.get(y);
                if (b == a) return false;
            } 
        }
        return true;
    }
};