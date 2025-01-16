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
    bool isValid(int val, long long mn, long long mx) {
        return (val >= mn && val <= mx);
    }
    bool f(TreeNode* root, long long mn = INT64_MIN, long long mx = INT64_MAX) {
        if (!root) {
            return true;
        }

        bool left = f(root -> left, mn, (1LL * root -> val - 1));
        bool right = f(root -> right, (1LL * root -> val + 1), mx);

        return left && right && isValid(root -> val, mn, mx);
    }
    bool isValidBST(TreeNode* root) {
        return f(root);
    }
};