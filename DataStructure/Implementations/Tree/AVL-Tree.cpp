#include<bits/stdc++.h>
using namespace std;
#define COUNT 10

class Node {
public:
    int data;
    int height;
    int balancingFactor;
    Node *left;
    Node* right;
    
    Node(int val) {
        data = val;
        height = 0;
        balancingFactor = 0;
        left = right = nullptr;
    }
};

class AVLTree {
public:
    AVLTree() {
        root = nullptr;
        sz = 0;
    }

    // Insert the value in AVL Tree
    bool insert(int val) {
        if(this->find(val)) {
            return false;
        }
        root = this -> ins(this -> root, val);
        sz++;
    }

    // Search the given value
    bool find(int val) {
        return this -> find(this -> root, val);
    }

    // Horizontal Printing of the tree 
    void display() {
        this -> dis(this -> root, 0);
        cout << "\n";
    }

    // Remove the value from tree
    bool remove(int val) {
        if(!find(val)) {
            return false;
        }
        sz--;
        root = removeUtil(this -> root, val);
        return true;
    }

    // Get size of the AVL Tree
    int size() {
        return sz;
    }

    // returns the order of the key compared to the existing elements i.e., how many elements are smaller than key 
    int orderOfKey(int val) {
        return countUtil(this -> root, val);
    }

    // returns the  k’th element among the existing keys, if k is greater than the size of AVL then it will return the last greatest element
    int getByOrder(int k) {
        if(root == nullptr) {
            return -1;
        }

        if(k > sz) {
            return maxElementInAVL(root);
        }
        int count = 0;
        return kthElement(root, k, count);
    }
private:
    Node * root;
    int sz;

    void dis(Node* root, int space) {
        if(root == nullptr)
            return;
        
        space += COUNT;
        dis(root -> right, space);

        for(int i = COUNT; i < space; i++) {
            cout << " ";
        }
        cout << root -> data << "\n";

        dis(root -> left, space);
    }
    // Private Method to add a new node, It will insert the node and it will return the root node of updated tree. 
    Node* ins(Node* root, int val) {
        if(root == nullptr) {
            return new Node(val);
        }

        if(root -> data < val) {
            root -> right = ins(root -> right, val);
        } else if(root -> data > val) {
            root -> left = ins(root -> left, val);
        }

        this -> update(root);

        return this -> balance(root);
    }

    // This will update the heights and balance factor of given node
    void update(Node* root) {
        int leftHeight = -1, rightHeight = -1;

        if(root -> left != nullptr) {
            leftHeight = root -> left -> height;
        } 
        if(root -> right != nullptr) {
            rightHeight = root -> right -> height; 
        }
        root -> height = 1 + max(rightHeight, leftHeight);
        root -> balancingFactor = rightHeight - leftHeight;
    }

    Node* rotateRight(Node* root) {
        Node* leftChild = root -> left;
        root -> left = leftChild -> right;
        leftChild -> right = root;

        update(root);
        update(leftChild);
        return leftChild;
    }

    Node* rotateLeft(Node* root) {
        Node* rightChild = root -> right;
        root -> right = rightChild -> left;
        rightChild -> left = root;

        update(root);
        update(rightChild);
        return rightChild;
    }
    // left-left case
    Node* leftLeftCase(Node* root) {
        return rotateRight(root);
    }

    // Left - right case
    Node* leftRightCase(Node* root) {
        root -> left = rotateLeft(root -> left);
        return leftLeftCase(root);
    }

    // Right -right case
    Node* rightRightCase(Node* root) {
        return rotateLeft(root);
    }

    // Right - Left Case
    Node* rightLeftCase(Node* root) {
        root -> right = rotateRight(root -> right);
        return rightRightCase(root);
    }

    // This method will check for unbalance codition for AVL Tree and if the tree is unbalanced then this will balance the tree and return the node after balancing it.
    Node* balance(Node* root) {
        // Left side more weighted
        if(root -> balancingFactor == -2) {
            // left- left
            if(root -> left -> balancingFactor <= 0) {
                return leftLeftCase(root);
            } else {
                return leftRightCase(root);
            }
        }

        // Right side more weighted
        if(root -> balancingFactor == 2) {
            // right - right
            if(root -> right -> balancingFactor >= 0) {
                return rightRightCase(root);
            } else {
                return rightLeftCase(root);
            }
        }
        return root;
    }

    bool find(Node* root, int val) {
        if(root == nullptr) {
            return false;
        }

        if(root -> data == val) {
            return true;
        }
        else if(root -> data < val) {
            return find(root -> right, val);
        } else {
            return find(root -> left, val);
        }

        return false;
    }
    
    // Utility function to remove the given value
    Node* removeUtil(Node* root, int val) {
        if(root == nullptr) {
            return root;
        }

        if(root -> data < val) {
            root -> right = removeUtil(root -> right, val);
        } else if(root -> data > val) {
            root -> left = removeUtil(root -> left, val);
        } else {
            // Child Node
            if(root -> left == nullptr && root -> right == nullptr) {
                delete root;
                return nullptr;
            } 
            // Right child is null
            else if(root -> right == nullptr) {
                Node* temp = root -> left;
                delete root;
                return temp;
            }
            // Left child is null
            else if(root -> left == nullptr) {
                Node *temp = root -> right;
                delete root;
                return temp;
            }
            // Both child are present
            else {
                Node* predecessor = root -> left;
                while(predecessor -> right) {
                    predecessor = predecessor -> right;
                }

                root -> data = predecessor -> data;
                root -> left = removeUtil(root -> left, predecessor -> data);

                update(root);
                return balance(root);
            }
        }

        update(root);
        return balance(root);
    }

    // Utility method for orderOfKey()
    int countUtil(Node* root, int val) {
        if (root == nullptr) {
            return 0;
        }

        if (root -> data < val) {
            int leftCnt = countUtil(root -> right, val);
            return 1 + countUtil(root -> left, val) + leftCnt;
        } else {
            return countUtil(root -> left, val);
        }
    }

    int maxElementInAVL(Node* root) {
        if(root == nullptr) {
            return -1;
        }
        Node* temp = root -> right;

        while(root -> right) {
            root = root -> right;
        } 
        return root -> data;
    }

    int kthElement(Node* root, int k, int &count) {
        if(root == nullptr) {
            return -1; 
        }

        int left = kthElement(root -> left, k, count);

        if(left != -1) {
            return left;
        }

        count++;
        if(count == k) {
            return root -> data;
        }

        return kthElement(root -> right, k, count);
    }
};


int main() {
    AVLTree avl;
    avl.insert(10);
    avl.insert(2);
    avl.insert(1);
    avl.insert(11);

    avl.insert(19);
    avl.insert(3);
    avl.insert(12);
    avl.insert(6);
    avl.insert(15);

    // avl.remove(10);
    // avl.remove(1);
    // avl.remove(3);
    cout << "Size: " << avl.size() << '\n';
    avl.display();

    int cnt = avl.orderOfKey(15);
    cout << "Order of 19: " << cnt << '\n'; 

    cout << "10th element : " << avl.getByOrder(8) << '\n';
}