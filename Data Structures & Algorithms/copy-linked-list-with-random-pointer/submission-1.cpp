/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> dict;
        Node* cur = head;
        Node* pre = nullptr;
        while (cur) {
            Node* node = new Node(cur->val);
            dict[cur] = node;
            if (pre) dict[pre]->next = dict[cur];
            pre = cur;
            cur = cur->next;
        }
        cur = head;
        while (cur) {
            dict[cur]->random = dict[cur->random];
            cur = cur->next;
        }
        return dict[head];
    }
};
