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
    vector<vector<int>> ans;
    void allPath(TreeNode* root, vector<int> &path, int sum, int targetSum) {
        if (!root) {
            return;
        }
        sum += root -> val;
        path.push_back(root -> val);

        if (!root -> left && !root -> right && sum == targetSum) {
            ans.push_back(path);
        } else {
            allPath(root -> left, path, sum, targetSum); 
            allPath(root -> right, path, sum, targetSum); 
        }
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (!root) {
            return {};
        }
        vector<int> temp;
        allPath(root, temp, 0, targetSum);
        return ans;
    }
};