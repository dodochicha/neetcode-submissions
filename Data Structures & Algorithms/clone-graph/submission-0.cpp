/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) return nullptr;
        Node* ans = new Node(node->val);
        unordered_map<int, Node*> dict;
        dict[1] = ans;
        queue<Node*> q;
        q.push(node);
        while (!q.empty()) {
            Node* cur = q.front();
            for (auto neighbor: cur->neighbors) {
                if (!dict.count(neighbor->val)) {
                    Node* nei = new Node(neighbor->val);
                    q.push(neighbor);
                    dict[neighbor->val] = nei;
                }
                dict[cur->val]->neighbors.push_back(dict[neighbor->val]);
            }
            q.pop();
        }
        return ans;

    }
};
