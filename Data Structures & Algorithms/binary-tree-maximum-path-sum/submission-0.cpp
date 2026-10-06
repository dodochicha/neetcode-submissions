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
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        auto dfs = [&](this auto&& dfs, TreeNode* node) -> int {
            if (node->left == nullptr && node->right == nullptr) {
                ans = max(ans, node->val);
                return node->val;
            }
            int left_sum = (node->left == nullptr) ? 0 : dfs(node->left);
            int right_sum = (node->right == nullptr) ? 0 : dfs(node->right);
            ans = max(ans, node->val + max(0, right_sum) + max(0, left_sum));
            return node->val + max(0, max(left_sum, right_sum));
        };
        dfs(root);
        return ans;
    }
};
