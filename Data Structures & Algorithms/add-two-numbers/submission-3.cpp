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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* ans = l1;
        ListNode* pre1;
        ListNode* pre2;
        while (l1 != nullptr || l2 != nullptr) {
            int sum = carry;
            if (l1 == nullptr) {
                ListNode* tmp = l1;
                ListNode* pretmp = pre1;
                l1 = l2;
                l2 = tmp;
                pre1 = pre2;
                pre2 = pretmp;
                pre2->next = l1;
            }
            sum += l1->val;
            sum += (l2 != nullptr) ? l2->val : 0;
            carry = sum / 10;
            l1->val = sum % 10;
            pre1 = l1;
            pre2 = l2;
            l1 = l1->next;
            l2 = (l2) ? l2->next : nullptr;
        }
        if (carry == 1) {
            ListNode* node = new ListNode(1);
            pre1->next = node;
        }
        return ans;
    }
};
