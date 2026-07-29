class Solution {
public:
int ans = 1;
vector<vector<int>> adj;
int dfs(int u, string& s) {
    int mx1 = 0, mx2 = 0;
    for(int v : adj[u]) {
        int len = dfs(v, s);
        if(s[u] == s[v]) continue;
        if(len > mx1) {
            mx2 = mx1;
            mx1 = len;
        }
        else if(len > mx2) {
            mx2 = len;
        }
    }
    ans = max(ans, mx1 + mx2 + 1);
    return mx1 + 1;
}
    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        adj.assign(n, {});
        for(int i = 1; i < n; ++i) adj[parent[i]].push_back(i);
        dfs(0, s);
        return ans;
    }
};