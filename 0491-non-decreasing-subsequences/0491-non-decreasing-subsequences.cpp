class Solution {
public:
vector<vector<int>> ans;
vector<int> cur;
void dfs(vector<int>& nums, int idx) {
    if(cur.size() >= 2) ans.push_back(cur);
    unordered_set<int> used;
    for(int i = idx; i < nums.size(); ++i) {
        if(used.count(nums[i])) continue;
        if(!cur.empty() && nums[i] < cur.back()) continue;
        used.insert(nums[i]);
        cur.push_back(nums[i]);
        dfs(nums, i + 1);
        cur.pop_back();
    }
}
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        dfs(nums, 0);
        return ans;
    }
};