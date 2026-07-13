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
unordered_map<int, int> mp;
int idx = 0;
TreeNode* build(vector<int>& pre, vector<int>& in, int l, int r) {
    if(l > r) return nullptr;
    int val = pre[idx++];
    TreeNode* root = new TreeNode(val);
    int mid = mp[val];
    root->left = build(pre, in, l, mid - 1);
    root->right = build(pre, in, mid + 1, r);
    return root;
}
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i = 0; i < inorder.size(); ++i) mp[inorder[i]] = i;
        return build(preorder, inorder, 0, inorder.size() - 1);
    }
};