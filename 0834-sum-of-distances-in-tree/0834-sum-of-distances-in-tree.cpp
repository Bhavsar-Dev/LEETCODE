class Solution {
public:
    vector<vector<int>> adj;
    vector<int> cnt, ans;
    void dfs1(int u, int p, int d) {
        ans[0] += d;
        cnt[u] = 1;
        for(int v : adj[u]) {
            if(v == p) continue;
            dfs1(v, u, d + 1);
            cnt[u] += cnt[v];
        }
    }
    void dfs2(int u, int p, int n) {
        for(int v : adj[u]) {
            if(v == p) continue;
            ans[v] = ans[u] - cnt[v] + (n - cnt[v]);
            dfs2(v, u, n);
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        adj.resize(n);
        cnt.resize(n);
        ans.resize(n, 0);
        for(auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        dfs1(0, -1, 0);
        dfs2(0, -1, n);
        return ans;
    }
};