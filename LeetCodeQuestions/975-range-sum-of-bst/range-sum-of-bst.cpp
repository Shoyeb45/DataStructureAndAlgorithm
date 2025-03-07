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
    int rangeSumBST(TreeNode* root, int low, int high) {
        if (!root) {
            return 0;
        }

        int val = root -> val;
        int sum = 0;

        if (val > low) {
            sum += rangeSumBST(root -> left, low, high);
        }
        if (val < high) {
            sum += rangeSumBST(root -> right, low, high);
        }

        if (val >= low && val <= high) {
            sum += val;
        }
        return sum;
    }
};