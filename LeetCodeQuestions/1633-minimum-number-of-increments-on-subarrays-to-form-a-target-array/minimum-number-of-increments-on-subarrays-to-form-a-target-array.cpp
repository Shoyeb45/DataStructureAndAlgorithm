// Chat gpt
class Solution {
public:
    // A Node holds the minimum value in a segment and its index.
    struct Node {
        int val, idx;
    };

    vector<Node> segTree; // our segment tree storage
    int n;
    vector<int> arr;      // a copy of the original array

    // Merge two nodes: return the one with the smaller value.
    // In case of a tie, return the one with the greater index.
    Node mergeNode(const Node &left, const Node &right) {
        if (left.val < right.val)
            return left;
        else if (left.val > right.val)
            return right;
        else
            return (left.idx > right.idx ? left : right);
    }

    // Build the segment tree.
    // idx: current index in the segment tree (starting at 1)
    // low, high: current range in the array 'arr'
    void build(int idx, int low, int high) {
        if (low == high) {
            segTree[idx] = {arr[low], low};
            return;
        }
        int mid = (low + high) / 2;
        build(2 * idx, low, mid);
        build(2 * idx + 1, mid + 1, high);
        segTree[idx] = mergeNode(segTree[2 * idx], segTree[2 * idx + 1]);
    }

    // Query the segment tree for the minimum element in the range [L, R]
    Node query(int idx, int low, int high, int L, int R) {
        // No overlap
        if (R < low || L > high) {
            return {INT_MAX, -1};
        }
        // Complete overlap
        if (L <= low && high <= R) {
            return segTree[idx];
        }
        // Partial overlap: query both children.
        int mid = (low + high) / 2;
        Node leftNode = query(2 * idx, low, mid, L, R);
        Node rightNode = query(2 * idx + 1, mid + 1, high, L, R);
        return mergeNode(leftNode, rightNode);
    }

    // Our divide-and-conquer function.
    // It computes the minimum number of operations needed for the subarray [low, high],
    // given that the current "base" level is 'step'.
    int f(int low, int high, int step) {
        if (low > high)
            return 0;
        // Get the minimum element and its index in the current range using the segment tree.
        Node node = query(1, 0, n - 1, low, high);
        int minEle = node.val;
        int minIdx = node.idx;
        // We subtract the current step from minEle because previous operations have already
        // raised the base level.
        int ans = (minEle - step);
        // Recurse on the segments to the left and right of the minimum.
        ans += f(low, minIdx - 1, minEle);
        ans += f(minIdx + 1, high, minEle);
        return ans;
    }

    int minNumberOperations(vector<int>& a) {
        arr = a;
        n = arr.size();
        // Resize the segment tree to 4*n to be safe.
        segTree.resize(4 * n);
        build(1, 0, n - 1);
        return f(0, n - 1, 0);
    }
};
