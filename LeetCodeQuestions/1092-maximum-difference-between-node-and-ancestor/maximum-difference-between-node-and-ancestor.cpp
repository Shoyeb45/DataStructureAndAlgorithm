/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans = INT_MIN;
    /// first -> min, and second -> max
    pair<int, int> maxAnceDiff(TreeNode* root) {
        if (!root) {
            return make_pair(INT_MAX, INT_MIN);
        }

        if (!root -> left && !root -> right) {
            return make_pair(root -> val, root -> val);
        }

        auto left = maxAnceDiff(root -> left);
        auto right = maxAnceDiff(root -> right);

        int mn = min(left.first, right.first);
        int mx = max(left.second, right.second);
        ans = max({ans, abs(root -> val - mn), abs(root -> val - mx)});

        return make_pair(
            min(mn, root -> val),
            max(mx, root -> val)
        );
    }
    
    int maxAncestorDiff(TreeNode* root) {
        maxAnceDiff(root);
        return ans;
    }
};