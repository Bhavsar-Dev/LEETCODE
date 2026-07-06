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
int i = 0;
TreeNode* build(vector<int>& pre, int b) {
    if(i == pre.size() || pre[i] > b) return nullptr;
    TreeNode* root = new TreeNode(pre[i++]);
    root->left = build(pre, root->val);
    root->right = build(pre, b);
    return root;
}
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return build(preorder, INT_MAX);
    }
};