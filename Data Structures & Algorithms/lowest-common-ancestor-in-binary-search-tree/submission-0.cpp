class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path_to_p;
        vector<TreeNode*> path_to_q;
        vector<TreeNode*> path;
        TreeNode* ans = nullptr;

        auto dfs = [&](this auto&& dfs, TreeNode* cur) -> void {
            if (cur == nullptr) return;
            path.push_back(cur);
            if (cur == p) path_to_p = path;
            if (cur == q) path_to_q = path;
            dfs(cur->left);
            dfs(cur->right);
            path.pop_back();
        };

        dfs(root);
        size_t len = min(path_to_p.size(), path_to_q.size());
        for (size_t i = 0; i < len; i++) {
            if (path_to_p[i] == path_to_q[i]) {
                ans = path_to_p[i];
            } else {
                break;
            }
        }
        return ans;
    }
};