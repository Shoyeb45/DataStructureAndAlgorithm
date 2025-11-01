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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        if (!head) {
            return head;
        }
        if (!head -> next) {
            bool ok = false;
            for (int i = 0; i < nums.size(); i++) {
                if (head -> val == nums[i]) {
                    ok = true;
                    break;
                }
            }
            return ok ? nullptr: head;
        }
        sort(nums.begin(), nums.end());
        for (auto it = head; it -> next != nullptr; ) {
            if (binary_search(nums.begin(), nums.end(), it -> next -> val)) {
                it -> next = it -> next -> next;
            } else {
                it = it -> next;
            }
        }
        if (binary_search(nums.begin(), nums.end(), head -> val)) {
            head = head -> next;
        }

        return head;
    }
};