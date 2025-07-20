/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


class Codec {
private:
    string vecToString(vector<string> &a) {
        string ans = "";
        for (int i = 0; i < a.size(); i++) {
            if (i == a.size() - 1) {
                ans += a[i];
            } else {
                ans += a[i] + " ";
            }
        }

        return ans;
    }

    vector<string> toArr(string &s) {
        vector<string> ans;
        string temp = "";
        for (auto ch: s) {
            if (ch == ' ') {
                ans.push_back(temp);
                temp = "";
            } else {
                temp += ch;
            }
        }

        return ans;
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        vector<string> levelOrder;

        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* front = q.front();
            q.pop();

            if (front) {
                levelOrder.push_back(to_string(front -> val));
                q.push(front -> left);
                q.push(front -> right);
            } else {
                levelOrder.push_back("n");
            }
        }

  
        string data = vecToString(levelOrder);
        return data;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> levelOrder = toArr(data);
        if (levelOrder.empty() || levelOrder[0] == "n") {
            return nullptr;
        }
        
        for (auto s: levelOrder) {
            cout << s << "\n";
        }

        TreeNode* ans = new TreeNode(stoi(levelOrder[0]));
        queue<TreeNode*> q;
        q.push(ans);
        // [1, 2, 3, n, n, 4, 5]


        int i = 1;
        while (i < levelOrder.size() && !q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (levelOrder[i] != "n") {
                node -> left = new TreeNode(stoi(levelOrder[i]));
                q.push(node -> left);
            }
            i++;
            if (i < levelOrder.size() && levelOrder[i] != "n") {
                node -> right = new TreeNode(stoi(levelOrder[i]));
                q.push(node -> right);
            }
            i++;
            
        }

        return ans;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));