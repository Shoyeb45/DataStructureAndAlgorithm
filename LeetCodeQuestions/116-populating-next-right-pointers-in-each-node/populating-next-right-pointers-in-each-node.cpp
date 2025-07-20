/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);

class Solution {
public:
    Node* connect(Node* root) {
        NFS
        if (!root) {
            return root;
        }
        Node* curr = root;
        
        while (curr -> left != nullptr) {
            Node* temp = curr;
            while (temp) {
                
                temp -> left -> next = temp -> right;
                if (temp -> next) {
                    temp -> right -> next = temp -> next -> left; 
                }
                temp = temp -> next;
            }
            curr = curr -> left;
        }

        return root;
    }
};