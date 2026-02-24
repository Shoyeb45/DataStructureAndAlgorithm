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
    int binary_to_num(string s) {
        cout << s << "\n";
        reverse(s.begin(), s.end());
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            ans += (1 << i) * (s[i] - '0');
        }
        return ans;
    }

    /*
        1 -> 0 -> 0
    */
    int sum = 0;
    void get_sum(TreeNode* node, string &s) {
        if (!node) return;
        if (!node->left && !node->right) {
            s += to_string(node->val);
            sum += binary_to_num(s);
            s.pop_back();
            return;
        }

        s += to_string(node->val);

        get_sum(node->left, s);
        get_sum(node->right, s);
        s.pop_back();        
    }
    
    int sumRootToLeaf(TreeNode* root) {
        if (!root) return 0;
        string s = "";
        get_sum(root, s);
        return sum;
    }
};