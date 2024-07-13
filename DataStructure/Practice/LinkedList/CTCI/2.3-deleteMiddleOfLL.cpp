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

void deleteMiddle(Node* &head) {
    if(head->next == NULL) {
        return;
    }
    int size = 0;
    Node* it = head;

    while(it != NULL) {
        it = it->next;
        size++;
    }

    int n = size/2 - 1;
    it = head;
    for(int i = 1; i <= n; i++) {
        it = it->next;
    }
    Node* temp = it->next;
    it->next = it->next->next;
    delete temp;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    LinkedList b;
    int n;
    cin >> n;
    loop(i, n) {
        int x; cin >> x;
        b.append(x);
    }

    deleteMiddle(b.head);
    
    cout << b;
    return 0;
}
