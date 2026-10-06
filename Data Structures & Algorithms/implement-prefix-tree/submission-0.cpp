class Node {
public:
    unordered_map<char, Node*> children;
    bool end = false;
};

class PrefixTree {
public:
    Node* root;
    PrefixTree() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* cur = root;
        for (char c: word) {
            if (cur->children.find(c) == cur->children.end()) {
                cur->children[c] = new Node();
            }
            cur = cur->children[c];
        }
        cur->end = true;
    }
    
    bool search(string word) {
        Node* cur = root;
        for (char c: word) {
            if (cur->children.find(c) == cur->children.end()) return false;
            else cur = cur->children[c];
        }
        return cur->end;
    }
    
    bool startsWith(string prefix) {
        Node* cur = root;
        for (char c: prefix) {
            if (cur->children.find(c) == cur->children.end()) return false;
            cur = cur->children[c];
        }
        return true;
    }
};
