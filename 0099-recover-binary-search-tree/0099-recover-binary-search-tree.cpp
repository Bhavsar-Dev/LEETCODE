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
TreeNode *fir = nullptr, *sec = nullptr, *prev = nullptr;
void inor(TreeNode* root) {
    if(!root) return;
    inor(root->left);
    if(prev && prev->val > root->val) {
        if(!fir) fir = prev;
        sec = root;
    }
    prev = root;
    inor(root->right);
}
    void recoverTree(TreeNode* root) {
        inor(root);
        swap(fir->val, sec->val);
    }
};