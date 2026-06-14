/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
using Node = ListNode;

class Solution {
public:
    int len(Node* head) {
        int n = 0;
        for (Node* it = head; it != nullptr; it = it->next) n++;
        return n;
    }

    Node* reverse(Node* head) {
        if (!head) return nullptr;
        if (!head->next) return head;

        Node *it = head, *next = head->next;
        it->next = nullptr;

        while (next) {
            Node *it2 = next->next;
            next->next = it;
            it = next;
            next = it2;
        }

        return it;
    }
    
    int pairSum(ListNode* head) {
        Node* second_half_head = head;

        int n = len(head);

        for (int i = 0; i < n / 2; i++) {
            second_half_head = second_half_head->next;
        }

        second_half_head = reverse(second_half_head);

        int ans = INT_MIN;

        for (int i = 0; i < n / 2; i++) {
            ans = max(ans, second_half_head->val + head->val);
            second_half_head = second_half_head->next;
            head = head->next;
        }
        return ans;
    }
};

// 1 2 3 4 10 3 2 1