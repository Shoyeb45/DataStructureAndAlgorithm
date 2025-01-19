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

auto init = []() { 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.empty()) {
            return nullptr;
        }
        int mid = nums.size() / 2;

        vector<int> left, right;
        for (int i = 0; i < mid; i++) {
            left.push_back(nums[i]);
        }
        for (int i = mid + 1; i < nums.size(); i++) {
            right.push_back(nums[i]);
        }
        TreeNode* root = new TreeNode(nums[mid]);
        root -> left = sortedArrayToBST(left);
        root -> right = sortedArrayToBST(right);

        return root;
    }
};