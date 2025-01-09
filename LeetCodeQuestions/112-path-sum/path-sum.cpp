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
    bool ans = false;
    void check(TreeNode* root, int target, int sum = 0) {
        if (!root) {
            return;
        }
        if (!root -> right && !root -> left) {
            ans |= (sum + root -> val == target);
            return;
        }
        check(root -> left, target, sum + root -> val);
        check(root -> right, target, sum + root -> val);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) {
            return false;
        }

        check(root, targetSum);
        return ans;
    }
};