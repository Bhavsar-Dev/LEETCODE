class Solution {
public:
const int MOD = 1e9 + 7;
    int numOfArrays(int n, int m, int k) {
        vector<vector<vector<long long>>> dp(n + 1, vector<vector<long long>>(m + 1, vector<long long>(k + 1, 0)));
        for(int mx = 1; mx <= m; ++mx) dp[1][mx][1] = 1;
        for(int len = 2; len <= n; ++len) {
            for(int mx = 1; mx <= m; ++mx) {
                for(int cst = 1; cst <= k; ++cst) {
                    dp[len][mx][cst] = (dp[len][mx][cst] + dp[len -1][mx][cst] * mx) % MOD;
                    long long sum = 0;
                    for(int p = 1; p < mx; ++p) {
                        sum += dp[len - 1][p][cst - 1];
                        sum %= MOD;
                    }
                    dp[len][mx][cst] = (dp[len][mx][cst] + sum) % MOD;
                }
            }
        }
        long long ans = 0;
        for(int mx = 1;mx <= m; ++mx) {
            ans = (ans + dp[n][mx][k]) % MOD;
        }
        return ans;
    }
};