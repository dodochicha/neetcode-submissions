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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return nullptr;
        if (lists.size() == 1) return lists[0];
        ListNode* ans = nullptr;
        for (int i = 0; i < lists.size(); i++) {
            ans = mergeTwoLists(ans, lists[i]);
        }
        return ans;
    }
private:
        ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
            if (l1 == nullptr && l2 == nullptr) return nullptr;
            if (l1 == nullptr) return l2;
            if (l2 == nullptr) return l1;
            ListNode* head;
            if (l1->val < l2->val) {
                head = l1;
                l1 = l1->next;
            }
            else {
                head = l2;
                l2 = l2->next;
            }
            ListNode* cur = head;
            while (l1 != nullptr && l2 != nullptr) {
                if (l1->val < l2->val) {
                    cur->next = l1;
                    l1 = l1->next;
                }
                else {
                    cur->next = l2;
                    l2 = l2->next;
                }
                cur = cur->next;
            }
            if (l1 == nullptr) cur->next = l2;
            else cur->next = l1;
            return head;
        };
};
