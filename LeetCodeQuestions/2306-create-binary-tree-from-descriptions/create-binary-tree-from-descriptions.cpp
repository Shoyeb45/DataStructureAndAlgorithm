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

    TreeNode* createBinaryTree(vector<vector<int>>& desc) {
        map<int, pair<int, int>> mp;

        static const auto fast_io = [](){
            std::ios::sync_with_stdio(false);
            std::cin.tie(nullptr);
            return nullptr;
        }();
        
        for (auto &x: desc) {
            if (mp.find(x[0]) != mp.end()) {
                if (x[2]) {
                    mp[x[0]].first = x[1];
                } else {
                    mp[x[0]].second = x[1];
                }
            } else {
                if (x[2]) {
                    mp[x[0]] = make_pair(x[1], -1);
                } else {
                    mp[x[0]] = make_pair(-1, x[1]);
                }
            }
        }
        
        set<int> st;
        for (auto x: mp) {
            st.insert(x.second.first);
            st.insert(x.second.second);
        }

        int rootVal = -1;
        for (auto x: mp) {
            if (!st.count(x.first)) {
                rootVal = x.first;
                break;
            }
        }
        
        TreeNode *root = new TreeNode(rootVal);
        
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (mp.find(node->val) == mp.end()) continue;

            auto p = mp[node->val];
            if (p.first != -1) {
                node->left = new TreeNode(p.first);
                q.push(node->left);
            }
            if (p.second != -1) {
                node->right = new TreeNode(p.second);
                q.push(node->right);
            }
        }

        return root;
    }
};