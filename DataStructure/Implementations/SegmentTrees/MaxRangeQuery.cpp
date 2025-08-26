# include<bits/stdc++.h>
using namespace std;

// In general be careful on below points:
// 1. What information of segment we store at tree[i], ex: max, min, sum, product
// 2. calculate value of segment using child segment
// 3. In case of non-overlapping , what to reture. ex: return INT_MAX for minimum, 0 for sum
// 4. using query of the left and right child, how can we get query of current node. 

/// @brief Range maximum query, we can do minimal changes to convert it into range minimum query, or range sum query
class RMQ {
public:
    vector<int> tree;
    int n;

    RMQ(int n) {
        this -> n = n;
        tree.resize(4 * n + 1);
    }

    void build(vector<int> &a) {
        build_sg(a, 0, n - 1, 0);
    }
    
    int find_max(int l, int r) {
        pair<int, int> idx = {l, r};
        return find_max_element({0, n - 1}, 0, idx);
    }
    
    void update(int index, int value) {
        point_update({0, n - 1}, 0, index, value);
    }
private:
    void build_sg(vector<int> &a, int l, int r, int i) {
        if (l == r) {
            tree[i] = a[l];
            return;
        }

        int mx = (l + r) / 2;
        build_sg(a, l, mx, 2 * i + 1);
        build_sg(a, mx + 1, r, 2 * i + 2);


        tree[i] = max(tree[2 * i + 1], tree[2 * i + 2]);
        return;
    }
    int find_max_element(pair<int, int> segRange, int i, pair<int, int> &queryRange) {
        // segment range is completely within the queryRange
        if (queryRange.first <= segRange.first && segRange.second <= queryRange.second) {
            return tree[i];
        }
        // if there is no overlapping 
        else if (isNoOverlapping(segRange, queryRange)) {
            return INT_MIN;
        }
        // partial overlapping 
        else {
            int m = (segRange.first + segRange.second) / 2;
            return max(
                find_max_element({segRange.first, m}, 2 * i + 1, queryRange),
                find_max_element({m + 1, segRange.second}, 2 * i + 2, queryRange)
            );
        }
    }

    void point_update(pair<int, int> segRange, int treeIndex, int updateIndex, int updateValue) {
        if (segRange.first == segRange.second && updateIndex == segRange.first) {
            tree[treeIndex] = updateValue;
            return;
        }

        if (updateIndex < segRange.first || updateIndex > segRange.second) {
            return;
        } 
        int m = (segRange.first + segRange.second) / 2;

        point_update({segRange.first, m}, 2 * treeIndex + 1, updateIndex, updateValue); // left
        point_update({m + 1, segRange.second}, 2 * treeIndex + 2, updateIndex, updateValue); // right
        tree[treeIndex] = max(tree[2 * treeIndex + 1], tree[2 * treeIndex + 2]);
        return;
    }
private:
    bool isNoOverlapping(pair<int, int> &q1, pair<int, int> &q2) {
        return q1.second < q2.first || q2.second < q1.first; 
    }   
};


int main() {
    
    vector<int> a = {1, -2, 3, 10, 3, 4};
    RMQ rmq(a.size());

    rmq.build(a);
    cout << rmq.find_max(1, 4) << "\n";
    cout << rmq.find_max(1, 2) << "\n";
    rmq.update(3, -10);
    cout << rmq.find_max(1, 4) << "\n";
}