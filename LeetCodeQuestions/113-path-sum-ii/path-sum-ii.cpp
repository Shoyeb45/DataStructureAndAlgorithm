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
    void allPath(TreeNode* root, vector<int> path, int sum, int targetSum) {
        if (!root) {
            return;
        }
        if (!root -> left && !root -> right) {
            sum += root -> val;
            path.push_back(root -> val);
            if (sum == targetSum) {
                ans.push_back(path);
            }
            return;
        }
        sum += root -> val;
        path.push_back(root -> val);
        allPath(root -> left, path, sum, targetSum); 
        allPath(root -> right, path, sum, targetSum); 
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (!root) {
            return {};
        }
        
        allPath(root, {}, 0, targetSum);
        return ans;
    }
};