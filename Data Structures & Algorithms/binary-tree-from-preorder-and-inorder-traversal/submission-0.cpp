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
unordered_map<int, int> mp;
int preIdx = 0;
public:
    TreeNode* build(vector<int>& preorder, int start, int end) {
        if (start > end) return nullptr;
        int rootVal = preorder[preIdx++];
        int mid = mp[rootVal];
        TreeNode* root = new TreeNode(rootVal);
        root->left = build(preorder, start, mid - 1);
        root->right = build(preorder, mid + 1, end);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }
        return build(preorder, 0, inorder.size() - 1);
    }
};
