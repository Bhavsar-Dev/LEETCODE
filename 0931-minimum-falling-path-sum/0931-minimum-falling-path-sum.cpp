class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n));
        for(int j = 0; j < n; ++j) dp[0][j] = matrix[0][j];
        for(int i = 1; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                dp[i][j] = dp[i - 1][j];
                if(j > 0) {
                    dp[i][j] = min(dp[i][j], dp[i- 1][j - 1]);
                }
                if(j + 1 < n) {
                    dp[i][j] = min(dp[i][j], dp[i - 1][j + 1]);
                }
                dp[i][j] += matrix[i][j];
            }
        }
        int ans = INT_MAX;
        for(int j = 0; j < n; ++j) {
            ans = min(ans, dp[n - 1][j]);
        }
        return ans;
    }
};