class Solution {
public:
    using ll = long long;
    long long minCost(int m, int n, vector<vector<int>>& penalty) {
        const ll INF = LLONG_MAX / 4;
        vector<vector<array<ll, 2>>> d(m, vector<array<ll, 2>>(n, {INF, INF}));
        using T = tuple<ll, int, int, int>;
        priority_queue<T, vector<T>, greater<T>> pq;
        d[0][0][1] = 1;
        pq.push({1, 0, 0, 1});
        int dr[4] = {1, -1, 0, 0};
        int dc[4] = {0, 0, 1, -1};
        while(!pq.empty()) {
            auto [cost, i, j, p] = pq.top();
            pq.pop();
            if(cost != d[i][j][p]) continue;
            if(i == m - 1 && j == n - 1) return cost;
            int np = 1 - p;
            ll nc = cost + penalty[i][j];
            if(nc < d[i][j][np]) {
                d[i][j][np] = nc;
                pq.push({nc, i, j, np});
            }
            for(int x = 0; x < 4; x++) {
                int ni = i + dr[x];
                int nj = j + dc[x];
                if(ni < 0 || nj < 0 || ni >= m || nj >= n) continue;
                bool ok;
                if(p == 1) ok = (x == 0 || x == 2);
                else ok = (x == 1 || x == 3);
                ll enter = 1LL * (ni + 1) * (nj + 1);
                nc = cost + enter;
                if(!ok) nc += penalty[i][j];
                if(nc < d[ni][nj][np]) {
                    d[ni][nj][np] = nc;
                    pq.push({nc, ni, nj, np});
                }
            }
        }
        return min(d[m - 1][n - 1][0], d[m - 1][n - 1][1]);
    }
};