#include <bits/stdc++.h>
using namespace std;
#define loop(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
const ll mod = 1000000007;

class Node {
public:
    int data;
    Node *next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class LinkedList {
public:
    Node *head;
    int sz;

    LinkedList() {
        head = NULL;
        sz = 0;
    }

    void append(int val) {
        Node *new_node = new Node(val);
        if (head == NULL) {
            head = new_node;
            sz++;
            return;
        }
        Node *it = head;
        while (it->next)
        {
            it = it->next;
        }
        it->next = new_node;
        sz++;
    }

    friend ostream &operator<<(ostream &os, LinkedList l) {
        Node *curr = l.head;
        while (curr) {
            os << curr->data << " -> ";
            curr = curr->next;
        }
        os << "NULL\n";
        return os;
    }
    int size() {
        return sz;
    }
};

Node* NthFromEnd(Node* head, int n) {
        int size = 0;

    Node* it = head;
    while (it) {
        it = it->next;
        size++;
    }
    n = size - n;

    if (n == 0) {
        return head;
    }

    Node* prev = head;
    for(int i = 0; i <= n - 1; i++) {
        prev = prev->next;
    }
   
    return prev;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    LinkedList b;
    int n, k;
    cin >> n >> k;
    loop(i, n) {
        int x; cin >> x;
        b.append(x);
    }

    Node* new_node = NthFromEnd(b.head, k);
        cout << new_node->data << '\n';
    return 0;
}
