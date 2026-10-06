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
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;
        ListNode* slow = head;
        ListNode* fast = head;
        while (slow->next && fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* cur = slow->next;
        ListNode* pre = nullptr;
        slow->next = nullptr;
        while (cur) {
            ListNode* nexttmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nexttmp;
        }
        ListNode* first = head;
        ListNode* second = pre;
        while (second) {
            ListNode* firstnxt = first->next;
            ListNode* secondnxt = second->next;
            first->next = second;
            second->next = firstnxt;
            first = firstnxt;
            second = secondnxt;
        }
    }
};
