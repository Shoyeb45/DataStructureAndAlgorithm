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
    int maxSum(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int left = maxSum(root -> left);
        int right = maxSum(root -> right);

        int temp = max ({left, right, 0}) + root -> val;

        ans = max (ans, max(left + right + root -> val, temp));

        return temp;
    }
    int maxPathSum(TreeNode* root) {
        if (!root) {
            return 0;
        }
        maxSum(root);
        return ans;
    }   
};