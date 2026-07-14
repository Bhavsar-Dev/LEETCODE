class Solution {
public:
vector<vector<int>> adj;
int dfs(int u, int p, vector<bool>& has) {
    int ans = 0;
    for(int v : adj[u]) {
        if(v == p) continue;
        int t = dfs(v, u, has);
        if(t > 0 || has[v]) ans += t + 2;
    }
    return ans;
}
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        adj.resize(n);
        for(auto &e: edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        return dfs(0, -1, hasApple);
    }
};