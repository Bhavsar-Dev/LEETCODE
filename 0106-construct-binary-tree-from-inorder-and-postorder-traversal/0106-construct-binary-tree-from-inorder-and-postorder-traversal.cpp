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
int idx;
TreeNode* build(vector<int>& in, vector<int>& post, int l, int r) {
    if(l > r) return nullptr;
    int val = post[idx--];
    TreeNode* root = new TreeNode(val);
    int mid = mp[val];
    root->right = build(in, post, mid + 1, r);
    root->left = build(in, post, l, mid - 1);
    return root;
}
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i = 0; i < inorder.size(); ++i) mp[inorder[i]] = i;
        idx = postorder.size() -1;
        return build(inorder, postorder, 0, inorder.size() - 1);
    }
};