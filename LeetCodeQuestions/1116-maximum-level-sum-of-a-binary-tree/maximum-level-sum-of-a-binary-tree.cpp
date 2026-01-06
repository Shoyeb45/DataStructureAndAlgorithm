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
    int maxLevelSum(TreeNode* root) {
        int sum = root->val;
        int ans = 1;

        queue<TreeNode*> q;

        q.push(root);
        int lvl = 1;

        while (!q.empty()) {
            size_t sz = q.size();
            lvl++;
            int tmp = 0;
            bool is_node = false;

            for (int k = 0; k < sz; k++) {
                TreeNode* node = q.front();
                q.pop();

                TreeNode *left = node->left, *right = node->right;

                if (left) {
                    q.push(left);
                    tmp += left->val;
                    is_node = true;
                } 
                if (right) {
                    q.push(right);
                    tmp += right->val;
                    is_node = true;
                }
            }

            cout << lvl << " " << tmp << "\n";
            if (is_node && tmp > sum) {
                ans = lvl;
                sum = tmp;
            }
        }
        return ans;
    }
};