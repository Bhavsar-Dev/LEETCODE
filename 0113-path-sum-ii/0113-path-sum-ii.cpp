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
vector<vector<int>> ans;
    void dfs(TreeNode* root, int tar, int sum, vector<int>& v) {
        if(root == NULL) return;
        sum += root->val;
        v.push_back(root->val);
        if(root->left == NULL && root->right == NULL) {
            if(sum == tar) ans.push_back(v); 
        } 
        dfs(root->left, tar, sum, v);
        dfs(root->right, tar, sum, v);
        v.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> v;
        dfs(root, targetSum, 0, v);
        return ans;
    }
};