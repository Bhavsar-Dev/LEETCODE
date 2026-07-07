class Solution {
public:
    using ll = long long;
    vector<ll> dij(int s, int n, vector<vector<pair<int,int>>> &a) {
        vector<ll> d(n, 1e18);
        priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> q;
        d[s] = 0;
        q.push({0, s});
        while(!q.empty()) {
            auto [x, u] = q.top();
            q.pop();
            if(x > d[u]) continue;
            for(auto [v, w] : a[u]) {
                if(d[v] > x + w) {
                    d[v] = x + w;
                    q.push({d[v], v});
                }
            }
        }
        return d;
    }
    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> a(n);
        for(auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];
            a[u].push_back({v, w});
            a[v].push_back({u, w});
        }
        vector<ll> d1 = dij(0, n, a);
        vector<ll> d2 = dij(n - 1, n, a);
        ll t = d1[n - 1];
        vector<bool> ans(edges.size());
        for(int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            if ((d1[u] + w + d2[v] == t) || (d1[v] + w + d2[u] == t)) ans[i] = true;
        }
        return ans;
    }
};