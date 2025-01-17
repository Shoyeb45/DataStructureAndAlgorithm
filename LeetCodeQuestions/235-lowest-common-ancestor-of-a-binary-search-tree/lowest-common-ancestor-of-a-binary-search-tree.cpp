/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) {
            return root;
        }

        TreeNode* temp = root;
        if (p -> val > q -> val) {
            swap(p, q);
        }
        cout << p -> val << " " << q -> val << "\n";
        
        while (temp) {
            if (q -> val < temp -> val) {
                temp = temp -> left;
            }
            else if (p -> val > temp -> val){
                temp = temp -> right;
            }
            else {
                return temp;
            }
        }
        return temp;
    }
};