class Solution {
public:
    unordered_map<string, int> freq;
    vector<TreeNode*> result;

    string dfs(TreeNode* node) {
        if (!node) return "#";  // "#" represents null

        string left = dfs(node->left);
        string right = dfs(node->right);
        
        string serial = to_string(node->val) + "," + left + "," + right;

        // If we’ve seen this exact structure once before, it’s a duplicate
        if (++freq[serial] == 2) {
            result.push_back(node);
        }

        return serial;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        dfs(root);
        return result;
    }
};
