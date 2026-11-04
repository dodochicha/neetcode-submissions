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
    vector<int> rightSideView(TreeNode* root) {
        vector<TreeNode*> q;
        vector<int> ans;
        if (root) q.push_back(root);
        while (!q.empty()) {
            vector<TreeNode*> nxt_q;
            for (int i = 0; i < q.size(); i++) {
                if (q[i]->left) nxt_q.push_back(q[i]->left);
                if (q[i]->right) nxt_q.push_back(q[i]->right);
            }
            ans.push_back(q[q.size()-1]->val);
            q = std::move(nxt_q);
        }
        return ans;
    }
};
