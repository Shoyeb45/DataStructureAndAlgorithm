#include<bits/stdc++.h>
using namespace std;



template<typename T>
class MaxHeap {
    class Node {
        Node *left;
        Node *right;
        T data;

        Node(T val) {
            left = right = nullptr;
            data = val;
        }
    };
    Node *root;
    int sz;

public:
    T front() {
        return root -> data;
    }

    int size() {
        return sz;
    }

    bool empty() {
        return sz == 0;
    }

    void insert(T )
};

int main() {

    
    return 0;
}
