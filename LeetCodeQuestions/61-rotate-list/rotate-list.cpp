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
class Solution {
public:
    ListNode* reverse(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode* prev = head, *it = head->next;
        prev->next = nullptr;

        while (it != nullptr) {
            ListNode* nxt = it->next;
            // prev->next = nullptr;
            it->next = prev;
            prev = it;
            it = nxt;
        }
        return prev;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return nullptr;
        
        int n = 0;
        for (ListNode* it = head; it != nullptr; it = it->next) {
            n++;
        }
        k = k % n;
        

        ListNode* it = head;
        for (int i = 1; it != nullptr; it = it->next, i++) {
            if (i == n - k) break;
        }
        if (it == nullptr || it->next == nullptr) {
            return head;
        }
        ListNode* curr = it, *nxtHead = it->next;
        curr->next = nullptr;
      
        ListNode* last = nxtHead;
        while (last->next != nullptr) {
            last = last->next;
        }

        last->next = head;
        return nxtHead;
    }
};