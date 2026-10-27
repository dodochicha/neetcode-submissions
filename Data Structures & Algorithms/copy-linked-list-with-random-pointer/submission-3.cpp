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
        dict.reserve(100);
        Node* cur = head;
        while (cur) {
            Node* node = new Node(cur->val);
            dict[cur] = node;
            cur = cur->next;
        }
        cur = head;
        while (cur) {
            dict[cur]->next = dict[cur->next];
            dict[cur]->random = dict[cur->random];
            cur = cur->next;
        }
        return dict[head];
    }
};
