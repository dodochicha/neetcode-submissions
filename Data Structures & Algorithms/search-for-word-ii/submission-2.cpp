class Node {
public:
    unordered_map<char, Node*> children;
    int idx = -1;
    int ref = 0;
};
class Tries {
public:
    Node* root;
    Tries() {
        root = new Node();
    }
    void add(string word, int i) {
        Node* cur = root;
        cur->ref++;
        for (char c: word) {
            if (cur->children.find(c) == cur->children.end()) {
                cur->children[c] = new Node();
            }
            cur = cur->children[c];
            cur->ref++;
        }
        cur->idx = i;
    }
};
class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        const int DIR[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        const int m = board.size();
        const int n = board[0].size();
        vector<string> ans;
        Tries* tr = new Tries();
        for (int i = 0; i < words.size(); i++) {
            tr->add(words[i], i);
        }
        auto dfs = [&](auto&& self, int i, int j, Node* node) -> void {
            if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] == '*' || !node->children[board[i][j]]) return;
            char tmp = board[i][j];
            board[i][j] = '*';
            Node* pre = node;
            node = node->children[tmp];
            if (node->idx != -1) {
                ans.push_back(words[node->idx]);
                node->idx = -1;
                node->ref--;
                if (node->ref == 0) {
                    pre->children[tmp] = nullptr;
                    node = nullptr;
                    board[i][j] = tmp;
                    return;
                }
            }
            self(self, i+1, j, node);
            self(self, i-1, j, node);
            self(self, i, j+1, node);
            self(self, i, j-1, node);
            board[i][j] = tmp;
        };
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dfs(dfs, i, j, tr->root);
            }
        }
        return ans;
    }
};
