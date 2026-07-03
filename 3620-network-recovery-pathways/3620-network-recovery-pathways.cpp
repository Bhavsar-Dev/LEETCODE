class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
        vector<vector<pair<int,int>>> adj(n);
        vector<int> in(n);
        int mx = 0;
        for(auto &e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
            in[e[1]]++;
            mx = max(mx, e[2]);
        }
        queue<int> q;
        for(int i = 0; i < n; i++) {
            if(in[i] == 0) q.push(i);
        }
        vector<int> topo;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            topo.push_back(u);
            for(auto &[v, w] : adj[u]) {
                if(--in[v] == 0) q.push(v);
            }
        }
        auto pos = [&](int x) {
            const long long INF = 4e18;
            vector<long long> d(n, INF);
            d[0] = 0;
            for(int u : topo) {
                if(d[u] == INF) continue;
                if(u != 0 && u != n - 1 && !online[u]) continue;
                for(auto &[v, w] : adj[u]) {
                    if(w < x) continue;
                    if(v != n - 1 && !online[v]) continue;
                    d[v] = min(d[v], d[u] + 1LL * w);
                }
            }
            return d[n - 1] <= k;
        };
        int l = 0, r = mx, ans = -1;
        while(l <= r) {
            int m = l + (r - l) / 2;
            if(pos(m)) {
                ans = m;
                l = m + 1;
            } else r = m - 1;
        }
        return ans;
    }
};