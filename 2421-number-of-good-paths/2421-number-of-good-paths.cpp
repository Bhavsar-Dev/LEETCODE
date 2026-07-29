class Solution {
public:
vector<int> p,sz;
int find(int x) {
    if(p[x] == x) return x;
    return p[x] = find(p[x]);
}
void uni(int a, int b) {
    a = find(a);
    b = find(b);
    if(a == b) return;
    if(sz[a] < sz[b]) swap(a, b);
    p[b] = a;
    sz[a] += sz[b];
}
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size();
        vector<vector<int>> g(n);
        for(auto &e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        map<int, vector<int>> mp;
        for(int i = 0; i < n; ++i) {
            mp[vals[i]].push_back(i);
        }
        p.resize(n);
        sz.assign(n, 1);
        for(int i = 0; i < n; ++i) p[i] = i;
        int ans = n;
        for(auto &[val, nodes] : mp) {
            for(int u : nodes) {
                for(int v : g[u]) {
                    if(vals[v] <= val) uni(u, v);
                }
            }
            unordered_map<int, int> cnt;
            for(int u : nodes) cnt[find(u)]++;
            for(auto &[root, c] : cnt) ans += c * (c - 1) / 2;
        }
        return ans;
    }
};