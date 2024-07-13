#include <bits/stdc++.h>
using namespace std;
#define loop(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
const ll mod = 1000000007;

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};

class LinkedList
{
public:
    Node *head;
    int sz;

    LinkedList()
    {
        head = NULL;
        sz = 0;
    }

    void append(int val)
    {
        Node *new_node = new Node(val);
        if (head == NULL)
        {
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

    friend ostream &operator<<(ostream &os, LinkedList l)
    {
        Node *curr = l.head;
        while (curr)
        {
            os << curr->data << " -> ";
            curr = curr->next;
        }
        os << "NULL\n";
        return os;
    }
    int size()
    {
        return sz;
    }
};

Node *removeDuplicates(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;

    map<int, int> mp;
    Node *curr = head;
    Node *prev = nullptr;
    while (curr != nullptr)
    {
        if (mp[curr->data] == 0)
        {
            prev = curr;
            mp[curr->data]++;
            curr = curr->next;
        }
        else
        {
            Node *del = curr;
            prev->next = curr->next;
            curr = curr->next;
            delete del;
        }
    }
    return head;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    LinkedList b;
    int n;
    cin >> n;
    loop(i, n) {
        int x; cin >> x;
        b.append(x);
    }

    Node* new_node = removeDuplicates(b.head);
    while(new_node != NULL) {
        cout << new_node->data << ' ';
        new_node = new_node->next;
    }
    return 0;
}
