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
    long long ans = 0, tree_sum = 0;

    void trv(TreeNode* root) {
        if (root) {
            trv(root->left);
            trv(root->right);
            tree_sum += root->val;
        }
    }
    long long dfs(TreeNode* root, long long sum) {
        if (!root) return 0;
        if (!root->left && !root->right) return root->val;
        sum += root->val;
        

        long long left_sum = dfs(root->left, sum);
        long long right_sum = dfs(root->right, sum);
        // cout << "node: " << root->val << "\n";
        // cout << "l: " << left_sum << ", r: " << right_sum << "\n";

        // remove left one
        if (root->left) {
            long long tmp = tree_sum - left_sum;
            // cout << "removed left: " << tmp << " " << left_sum << "\n"; 
            long long mul = tmp * left_sum;
            ans = max(mul, ans);
        }

        // remove right one
        if (root->right) {
            long long tmp = tree_sum - right_sum;
            long long mul = tmp * right_sum;
            // cout << "removed right: " << tmp << " " << right_sum << "\n";
            ans = max(mul, ans);
        }

        return left_sum + right_sum + root->val;
    }

    int maxProduct(TreeNode* root) {
        trv(root);
        dfs(root, 0);
        
        int mod = 1e9 + 7;

        return int((long long)ans % mod);    
    }
};