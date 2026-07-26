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
    void dfs(TreeNode* root, int val, int d) {
        if(root == NULL) return;
        if(d == 2) {
            TreeNode* l = root->left;
            TreeNode* r = root->right;
            root->left = new TreeNode(val);
            root->right = new TreeNode(val);
            root->left->left = l;
            root->right->right = r;
            return;
        }
        dfs(root->left, val, d - 1);
        dfs(root->right, val, d - 1);
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1) {
            TreeNode* node = new TreeNode(val);
            node->left = root;
            return node;
        }
        dfs(root, val, depth);
        return root;
    }
};