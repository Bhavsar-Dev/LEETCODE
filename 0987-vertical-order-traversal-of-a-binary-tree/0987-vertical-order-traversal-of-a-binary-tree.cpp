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
    vector<tuple<int, int, int>> v;
    void dfs(TreeNode* root, int r, int c) {
        if(!root) return;
        v.push_back({c, r, root->val});
        dfs(root->left, r + 1, c - 1);
        dfs(root->right, r + 1, c + 1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        dfs(root, 0, 0);
        sort(v.begin(), v.end());
        vector<vector<int>> ans;
        int col = INT_MIN;
        for(auto &[c,r,val] : v) {
            if(c != col) {
                ans.push_back({});
                col = c;
            }
            ans.back().push_back(val);
        }
        return ans;
    }
};