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
auto init = []() { ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 'c'; }();

class Solution {
public:
    int ans = 0;
    void inorder(TreeNode* root, int &cnt, int k) {
        if(root == nullptr) {
            return;
        }

        inorder(root -> left, cnt, k);
        cnt++;
        // cout << "Node: " << root -> val << " cnt: " << cnt << '\n';
        if(cnt == k) {
            ans = root -> val;
            return;
        }
        inorder(root -> right, cnt, k);
    } 
    int kthSmallest(TreeNode* root, int k) {
        if(!root) {
            return -1;
        }

        int cnt = 0;
        inorder(root, cnt, k);
        return ans;
    }
};