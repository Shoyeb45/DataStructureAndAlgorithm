#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
const ll mod = 1000000007;

class Node {
    public: 
    int data;
    Node* next;

    Node (int val) {
        data = val;
        next = nullptr;
    }
};

class LinkedList {
    public:
    Node* head;

    public:
    LinkedList() {
        head = NULL;
    }

    void append(int val) {
        Node* new_node = new Node(val);
        if(head == NULL) {
            head = new_node;
        }
        Node* it = head;
        while(it->next) {
            it = it->next;
        }
        it->next = new_node;
        new_node->next = nullptr;
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
};

Node* interleave_linked_list(Node* &l1, Node* &l2) {
    if(!l1)
        return l2;
    if(!l2)
        return l1;
    
    Node* ans = l1;
    Node* ptr1 = l1;
    Node* ptr2 = l2;

    while (l1 && l2) {
        Node* temp1 = l1->next;
        Node* temp2 = l2->next;
        if(!l1->next) {
            l1->next = l2;
            break;
        } 

        l1->next = l2;
        l2->next = temp1;
        l1 = temp1;
        l2 = temp2;
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;  cin >> n >> m;

    LinkedList a;
    LinkedList b;
    loop(i, n) {
        int x; cin >> x;
        a.append(x);
    }
    loop(i, m) {
        int x; cin >> x;
        b.append(x);
    }
    cout << a;
    cout << b;

    Node* ans = interleave_linked_list(a.head, b.head);

    while(ans) {
        cout << ans->data << " ";
        ans = ans->next;
    }
    cout << '\n';
    return 0;
}
