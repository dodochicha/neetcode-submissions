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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0, head);
        ListNode* groupPre = &dummy;
        ListNode* groupNext = &dummy;
        ListNode* cur = &dummy;
        int cnt = 0;
        while (cur->next) {
            cnt++;
            cur = cur->next;
            if (cnt == k) { // groupPre, group, groupNext
                cnt = 0;
                groupNext = cur->next;
                ListNode* rev = groupPre->next; // group[i]
                ListNode* revPre = groupPre; // group[i-1]
                ListNode* tmp = rev; // group[0]
                for (int i = 0; i < k; i++) {
                    ListNode* tmprevNext = rev->next; // group[i+1]
                    ListNode* tmprev = rev;
                    if (i == 0) {
                        rev->next = groupNext;
                        cur = rev;
                    }
                    else {
                        rev->next = revPre;
                    }
                    if (i == k - 1) {
                        groupPre->next = rev;
                        groupPre = tmp;
                    }
                    revPre = tmprev;
                    rev = tmprevNext;
                }
            }
        }
        return dummy.next;
    }
};
