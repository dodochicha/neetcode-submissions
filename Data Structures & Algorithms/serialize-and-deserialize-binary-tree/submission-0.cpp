/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        auto dfs_serialize = [&](this auto&& dfs_serialize, TreeNode* node, string& res) -> void {
            if (node == nullptr) {
                res += "N,";
                return;
            }
            res += to_string(node->val) + ",";
            dfs_serialize(node->left, res);
            dfs_serialize(node->right, res);
        };
        string res = "";
        dfs_serialize(root, res);
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        auto dfs_deserialize = [&](this auto&& dfs_deserialize, vector<string>& nodes, int& index) -> TreeNode* {
            if (index >= nodes.size() || nodes[index] == "N") {
                index++;
                return nullptr;
            }
            TreeNode* node = new TreeNode(stoi(nodes[index++]));
            node->left = dfs_deserialize(nodes, index);
            node->right = dfs_deserialize(nodes, index);
            return node;
        };
        stringstream ss(data);
        vector<string> nodes;
        string item;
        int index = 0;
        while (getline(ss, item, ',')) {
            nodes.push_back(item);
        }
        return dfs_deserialize(nodes, index);
    }
};
