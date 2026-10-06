class Node {
public:
    unordered_map<char, Node*> children;
    bool end = false;
};
class WordDictionary {
public:
    Node* root;
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
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
        auto dfs = [&](auto&& self, string word, Node* cur) {
            if (word.size() == 0) return cur->end;
            if (word[0] == '.') {
                for (int i = 0; i < 26; i++) {
                    if (cur->children.find('a'+i) == cur->children.end()) continue;
                    if (self(self, word.substr(1), cur->children['a'+i])) return true;
                }
            }
            else {
                if (cur->children.find(word[0]) == cur->children.end()) return false;
                if (self(self, word.substr(1), cur->children[word[0]])) return true;
            }
            return false;
        };
        return dfs(dfs, word, root);
    }
};
