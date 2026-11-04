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

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        auto dfs = [&](this auto& dfs, TreeNode* node, int l, int r) {
            if (!node) return true;
            if (node->val <= l || node->val >= r) return false;
            return dfs(node->left, l, node->val) && dfs(node->right, node->val, r);
        };
        return dfs(root, INT_MIN, INT_MAX);
    }
};
