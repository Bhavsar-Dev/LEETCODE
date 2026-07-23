class Solution {
public:
    int solve(vector<vector<int>>& g, int n) {
        vector<vector<int>> dp(n, vector<int>(n, -1));
        dp[n - 1][n  -1] = 0;
        for(int r = n - 2; r >= 0; --r) {
            int l = max(r + 1, n - 1 - r);
            for(int c = l; c < n; ++c) {
                int m = -1;
                for(int dc = -1; dc <= 1; ++dc){
                    int nc = c + dc;
                    if(nc >= 0 && nc < n && dp[r + 1][nc] != -1) {
                        m = max(m, dp[r +1][nc]);
                    }
                }
                if(m != -1) {
                    dp[r][c] = g[r][c] + m;
                }
            }
        }
        return dp[0][n - 1];
    }
    int maxCollectedFruits(vector<vector<int>>& g) {
        int n = g.size(), ans = 0;
        for(int i = 0; i < n; ++i) ans+=g[i][i];
        ans += solve(g, n);
        vector<vector<int>> t(n, vector<int>(n));
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                t[i][j] = g[j][i];
            }
        }
        ans += solve(t, n);
        return ans;
    }
};