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
    vector<int> inorderTraversal(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }

        vector<int> ans;

        TreeNode* curr = root;

        while (curr) {
            cout << curr -> val << " ";
            if (curr -> left == nullptr) {
                ans.push_back(curr -> val);
                curr = curr -> right;
            } else {
                TreeNode* temp = curr -> left;
                while (temp) {
                    if (temp -> right == curr) {
                        ans.push_back(curr -> val);
                        temp -> right = nullptr;
                        curr = curr -> right;
                        break;
                    } else if (temp -> right == nullptr) {
                        temp -> right = curr;
                        curr = curr -> left;
                        break;
                    }
                    temp = temp -> right;
                }
                
            }
        }

        return ans;
    }
};