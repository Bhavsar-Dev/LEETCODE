class Solution {
public:
void dfs(int u, vector<vector<pair<int, int>>> &adj, vector<int> &vis, int &ans) {
    vis[u] = 1;
    for(auto &[v, w] : adj[u]) {
        ans = min(ans, w);
        if(!vis[v]) dfs(v, adj, vis, ans);
    }
}
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for(auto &e : roads) {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }
        vector<int> vis(n + 1, 0);
        int ans = INT_MAX;
        dfs(1, adj, vis, ans);
        return ans;
    }
};