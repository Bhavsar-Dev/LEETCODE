class Solution {
public:
    int dp[301][11];
    int solve(int i, int d, vector<int>& job) {
        int n = job.size();
        if(d == 1) {
            int mx = 0;
            for(int k = i; k < n; ++k) {
                mx = max(mx, job[k]);
            }
            return mx;
        }
        if(dp[i][d] != -1) return dp[i][d];
        int ans = INT_MAX, mx = 0;
        for(int j = i; j <= n - d; ++j) {
            mx = max(mx, job[j]);
            ans = min(ans, mx + solve(j  +1, d - 1, job));
        }
        return dp[i][d] = ans;
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        if(n < d) return -1;
        memset(dp, -1, sizeof(dp));
        return solve(0, d, jobDifficulty);
    }
};