class Solution {
public:
vector<vector<int>> ans;
vector<int> cur;
void dfs(vector<int>& nums, vector<bool>& vis) {
    if(cur.size() == nums.size()) {
        ans.push_back(cur);
        return;
    }
    for(int i = 0; i < nums.size(); ++i) {
        if(vis[i]) continue;
        vis[i] = true;
        cur.push_back(nums[i]);
        dfs(nums, vis);
        cur.pop_back();
        vis[i] = false;
    }
}
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> vis(nums.size(), false);
        dfs(nums, vis);
        return ans;
    }
};