class Solution {
public:
vector<vector<int>> ans;
vector<int> cur;
void dfs(int st, int n, int k) {
    if(cur.size() == k) {
        ans.push_back(cur);
        return;
    }
    for(int i = st; i <= n; ++i) {
        cur.push_back(i);
        dfs(i + 1, n, k);
        cur.pop_back();
    }
}
    vector<vector<int>> combine(int n, int k) {
        dfs(1, n, k);
        return ans;
    }
};