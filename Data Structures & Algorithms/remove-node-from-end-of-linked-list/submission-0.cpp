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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int i = 1;
        int len = 1;
        ListNode* prehead = new ListNode(-1, head);
        ListNode* pre = prehead;
        ListNode* cur = head;
        while (cur->next != nullptr) {
            cur = cur->next;
            len++;
        }
        int removeId = len - n;
        len = 0;
        cur = head;
        while (cur->next != nullptr) {
            if (removeId == len) break;
            pre = cur;
            cur = cur->next;
            len++;
        }
        if (!cur->next) {
            pre->next = nullptr;
        }
        else {
            pre->next = cur->next;
        }
        return prehead->next;
    }
};
