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
    int goodNodes(TreeNode* root) {
        int ans = 0;
        auto dfs = [&](this auto& dfs, TreeNode* node, int upper) {
            if (!node) return;
            if (node->val >= upper) ans++;
            dfs(node->left, max(upper, node->val));
            dfs(node->right, max(upper, node->val));
        };
        dfs(root, INT_MIN);
        return ans;
    }
};
