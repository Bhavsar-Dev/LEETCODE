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
    struct NodeInfo {
        bool isbst;
        int sum;
        int minv;
        int maxv;
    };
    int ans = 0;
    NodeInfo dfs(TreeNode* root) {
        if (!root) return {true, 0, INT_MAX, INT_MIN};
        NodeInfo left = dfs(root->left);
        NodeInfo right = dfs(root->right);
        if (left.isbst && right.isbst && root->val > left.maxv && root->val < right.minv) {
            int curs = left.sum + right.sum + root->val;
            ans = max(ans, curs);
            return { true, curs, min(root->val, left.minv), max(root->val, right.maxv)
            };
        }
        return {false, 0, INT_MIN, INT_MAX};
    }
    int maxSumBST(TreeNode* root) {
        dfs(root);
        return ans;
    }
};